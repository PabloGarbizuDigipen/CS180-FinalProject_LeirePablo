/**
 * @file encryption.h
 * @brief Header file for encryption methods.
 * 
 * This file contains the declarations of encryption methods such as
 * XOR, BitShift, and RSA. These methods are used for secure file encryption.
 * 
 * @author
 * - Pablo Garbizu
 * - Leire Camacho
 * 
 * @date November 25, 2024
 */

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stddef.h>

void xor_encrypt(const unsigned char *input, unsigned char *output, size_t length, const char *key);
void bitshift_encrypt(const unsigned char *input, unsigned char *output, size_t length, int shift, const char *key);

#endif // ENCRYPTION_H
