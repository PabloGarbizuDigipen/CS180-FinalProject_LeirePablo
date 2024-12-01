/**
 * @file threading.c
 * @brief Implementation of multithreading support.
 * 
 * This file provides implementations of threading functions declared
 * in threading.h. These functions enable efficient file encryption and
 * decryption by leveraging multithreading to process file chunks concurrently.
 * 
 * @see threading.h
 * 
 * @date November 25, 2024
 */

#include "../include/threading.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 4
#define CHUNK_SIZE 1024

// Thread Function
void *process_chunk(void *arg)
{
    ThreadArgs *args = (ThreadArgs *)arg;
    if (args->method == 1) {
        if (args->decrypt)
            xor_decrypt(args->input, args->output, args->length, args->key);
        else
            xor_encrypt(args->input, args->output, args->length, args->key);
    } else if (args->method == 2) {
        if (args->decrypt)
            bitshift_decrypt(args->input, args->output, args->length, args->shift, args->key);
        else
            bitshift_encrypt(args->input, args->output, args->length, args->shift, args->key);
    }
    return NULL;
}

void process_file_with_threads(const char *input_file, const char *output_file, const char *key, int shift, int method, bool decrypt)
{
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        perror("Failed to open files");
        if (input) fclose(input);
        if (output) fclose(output);
        return;
    }

    unsigned char input_buffer[CHUNK_SIZE];
    unsigned char output_buffer[CHUNK_SIZE];
    pthread_t threads[THREAD_COUNT];
    ThreadArgs thread_args[THREAD_COUNT];

    size_t bytes_read;
    size_t total_chunks = 0;

    while ((bytes_read = fread(input_buffer, 1, CHUNK_SIZE, input)) > 0) {
        // Split the buffer among threads
        size_t chunk_size = bytes_read / THREAD_COUNT;
        size_t remaining = bytes_read % THREAD_COUNT;

        for (int i = 0; i < THREAD_COUNT; i++) {
            size_t offset = i * chunk_size;
            thread_args[i].input = input_buffer + offset;
            thread_args[i].output = output_buffer + offset;
            thread_args[i].length = (i == THREAD_COUNT - 1) ? chunk_size + remaining : chunk_size;
            thread_args[i].key = key;
            thread_args[i].shift = shift;
            thread_args[i].method = method;
            thread_args[i].decrypt = decrypt;

            if (pthread_create(&threads[i], NULL, process_chunk, &thread_args[i]) != 0) {
                perror("Failed to create thread");
                fclose(input);
                fclose(output);
                return;
            }
        }

        // Wait for all threads to finish
        for (int i = 0; i < THREAD_COUNT; i++) {
            pthread_join(threads[i], NULL);
        }

        // Write the processed data to the output file
        fwrite(output_buffer, 1, bytes_read, output);
        total_chunks++;
    }

    fclose(input);
    fclose(output);
    printf("File processed in %zu chunks.\n", total_chunks);
}
