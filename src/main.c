/**
 * @file main.c
 * @brief Main entry point for the HACKER file encryption tool.
 * 
 * This file implements the main function for the program. It handles
 * user interaction, such as selecting encryption or decryption,
 * specifying files, and choosing the encryption method.
 * 
 * @date November 25, 2024
 */

#include "../include/encryption.h"
#include "../include/decryption.h"
#include "../include/threading.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_menu() {
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
}

int main() {
    int choice;
    char input_file[256], output_file[256], key[256];
    int shift;

    show_menu();
    scanf("%d", &choice);

    printf("Enter input file path: ");
    scanf("%s", input_file);
    printf("Enter output file path: ");
    scanf("%s", output_file);
    printf("Enter key: ");
    scanf("%s", key);

    if (choice == 1) {
        printf("Choose encryption method (1: XOR, 2: BitShift, 3: RSA): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                process_file_with_threads(input_file, output_file, key, 0, xor_encrypt);
                break;
            case 2:
                printf("Enter bit shift amount: ");
                scanf("%d", &shift);
                process_file_with_threads(input_file, output_file, key, shift, bitshift_encrypt);
                break;
            case 3:
                rsa_encrypt(input_file, output_file, key);
                break;
        }
    } else if (choice == 2) {
        printf("Choose decryption method (1: XOR, 2: BitShift, 3: RSA): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                process_file_with_threads(input_file, output_file, key, 0, xor_decrypt);
                break;
            case 2:
                printf("Enter bit shift amount: ");
                scanf("%d", &shift);
                process_file_with_threads(input_file, output_file, key, shift, bitshift_decrypt);
                break;
            case 3:
                rsa_decrypt(input_file, output_file, key);
                break;
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
