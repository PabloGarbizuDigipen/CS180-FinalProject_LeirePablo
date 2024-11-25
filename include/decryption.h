/**
 * @file decryption.h
 * @brief Header file for decryption methods.
 * 
 * This file contains the declarations of decryption methods such as
 * XOR, BitShift, and RSA. These methods are used for secure file decryption.
 * 
 * @author
 * - Pablo Garbizu
 * - Leire Camacho
 * 
 * @date November 25, 2024
 */

#ifndef DECRYPTION_H
#define DECRYPTION_H

#include <stddef.h>

void xor_decrypt(const unsigned char *input, unsigned char *output, size_t length, const char *key);
void bitshift_decrypt(const unsigned char *input, unsigned char *output, size_t length, int shift, const char *key);
void rsa_decrypt(const char *input_file, const char *output_file, const char *private_key_file);

#endif // DECRYPTION_H
