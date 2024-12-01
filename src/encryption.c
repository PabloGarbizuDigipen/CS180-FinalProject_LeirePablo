/**
 * @file encryption.c
 * @brief Implementation of encryption methods.
 * 
 * This file implements the encryption methods declared in encryption.h.
 * These methods include:
 * - XOR encryption
 * - BitShift encryption
 * - RSA encryption
 * 
 * @see encryption.h
 * 
 * @date November 25, 2024
 */

#include "../include/encryption.h"
#include <string.h>  // For key manipulation
#include <stdio.h>   // For file I/O

void xor_encrypt(const unsigned char *input, unsigned char *output, size_t length, const char *key) {
    size_t key_len = strlen(key);
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

void bitshift_encrypt(const unsigned char *input, unsigned char *output, size_t length, int shift, const char *key) {
    size_t key_len = strlen(key);
    for (size_t i = 0; i < length; i++) {
        output[i] = (input[i] << shift) | (input[i] >> (8 - shift));
        if (key_len > 0) {
            output[i] ^= key[i % key_len];
        }
    }
}

void simple_encrypt(const unsigned char *input, unsigned char *output, size_t length, int shift, const char *key)
{
    for (size_t i = 0; i < length; i++)
    {
        output[i] = input[i] + shift; // Shift each character forward
    }
}

// void rsa_encrypt(const char *input_file, const char *output_file, const char *public_key_file) {
//     // Implement RSA encryption
//     printf("RSA encryption not yet implemented.\n");
// }

