/**
 * @file threading.h
 * @brief Header file for multithreading support.
 * 
 * This file declares structures and functions used to handle file processing
 * with multithreading, including dividing data into chunks and processing them
 * concurrently.
 * 
 * @author
 * - Pablo Garbizu
 * - Leire Camacho
 * 
 * @date November 25, 2024
 */

#ifndef THREADING_H
#define THREADING_H

#include <stddef.h>

typedef struct {
    const unsigned char *input;
    unsigned char *output;
    size_t length;
    const char *key;
    int shift;
    void (*encrypt_function)(const unsigned char *, unsigned char *, size_t, const char *);
} ThreadData;

void process_file_with_threads(const char *input_file, const char *output_file, const char *key, int shift, void (*encrypt_function)(const unsigned char *, unsigned char *, size_t, const char *));

#endif // THREADING_H
