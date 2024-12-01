/**
 * @file decryption.c
 * @brief Implementation of decryption methods.
 * 
 * This file implements the decryption methods declared in decryption.h.
 * These methods include:
 * - XOR decryption
 * - BitShift decryption
 * - RSA decryption
 * 
 * @see decryption.h
 * 
 * @date November 25, 2024
 */

#include "../include/decryption.h"
#include "../include/encryption.h" // xor_encrypt
#include <string.h>
#include <stdio.h>

void xor_decrypt(const unsigned char *input, unsigned char *output, size_t length, const char *key) {
    xor_encrypt(input, output, length, key); // XOR is symmetric
}

void bitshift_decrypt(const unsigned char *input, unsigned char *output, size_t length, int shift, const char *key) {
    size_t key_len = strlen(key);
    for (size_t i = 0; i < length; i++) {
        output[i] = (input[i] >> shift) | (input[i] << (8 - shift));
        if (key_len > 0) {
            output[i] ^= key[i % key_len];
        }
    }
}
