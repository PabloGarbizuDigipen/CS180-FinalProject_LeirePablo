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
    printf("1. Encrypt File\n");
    printf("2. Decrypt File\n");
}

int main() {
    int choice;
    int method;
    char input_file[256], output_file[256], key[256];
    int shift;

    printf("Choose an action: 1 (Encrypt), 2 (Decrypt): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    printf("Enter input file path: ");
    scanf("%s", input_file);
    printf("Enter output file path: ");
    scanf("%s", output_file);

    if (choice == 1) { // Encrypt
        printf("Choose encryption method:\n");
        printf("1: XOR\n2: BitShift\n3: Simple Shift\n4: Base64\n5: Vigenere\n6: Substitution\n7: Caesar\n");
        scanf("%d", &method);

        switch (method) {
            case 1:
                printf("Enter key for XOR encryption: ");
                scanf("%s", key);
                process_file_with_threads(input_file, output_file, key, 0, method, 0);
                break;
            case 2:
                printf("Enter bit shift amount: ");
                scanf("%d", &shift);
                printf("Enter key for BitShift encryption: ");
                scanf("%s", key);
                process_file_with_threads(input_file, output_file, key, shift, method, 0);
                break;
            case 3:
                printf("Enter shift amount for Simple Shift: ");
                scanf("%d", &shift);
                process_file_with_threads(input_file, output_file, NULL, shift, method, 0);
                break;
            default:
                printf("Invalid encryption method.\n");
        }
    } else if (choice == 2) { // Decrypt
        printf("Choose decryption method:\n");
        printf("1: XOR\n2: BitShift\n3: Simple Shift\n4: Base64\n5: Vigenere\n6: Substitution\n7: Caesar\n");
        scanf("%d", &method);

        switch (method) {
            case 1:
                printf("Enter key for XOR decryption: ");
                scanf("%s", key);
                process_file_with_threads(input_file, output_file, key, 0, method, 1);
                break;
            case 2:
                printf("Enter bit shift amount: ");
                scanf("%d", &shift);
                printf("Enter key for BitShift decryption: ");
                scanf("%s", key);
                process_file_with_threads(input_file, output_file, key, shift, method, 1);
                break;
            case 3:
                printf("Enter shift amount for Simple Shift: ");
                scanf("%d", &shift);
                process_file_with_threads(input_file, output_file, NULL, shift, method, 1);
                break;
            default:
                printf("Invalid decryption method.\n");
        }
    }

    return 0;
}



