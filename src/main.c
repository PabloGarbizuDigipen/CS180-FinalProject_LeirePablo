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
    printf("2. Decrypt\n\n");
}

int main() {
    int choice;
    char input_file[256], output_file[256], key[256];
    int shift;

    show_menu();

    while(choice < 1 || choice > 2)
    {
        printf("Enter the desired method: ");
        scanf("%d", &choice);

        if(choice < 1 || choice > 2)
        printf("Invalid choice, try again.\n");
    }

    printf("Enter input file path: ");
    scanf("%s", input_file);
    printf("Enter output file path: ");
    scanf("%s", output_file);
    printf("Enter key: ");
    scanf("%s", key);

    if (choice == 1) {
        printf("Choose encryption method (1: XOR, 2: BitShift): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                process_file_with_threads(input_file, output_file, key, 0, choice, 0);
                break;
            case 2:
                printf("Enter bit shift amount: ");
                scanf("%d", &shift);
                process_file_with_threads(input_file, output_file, key, shift, choice, 0);
                break;
        }
    }
    else if (choice == 2) {
        printf("Choose decryption method (1: XOR, 2: BitShift): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                process_file_with_threads(input_file, output_file, key, 0, choice, 1);
                break;
            case 2:
                printf("Enter bit shift amount: ");
                scanf("%d", &shift);
                process_file_with_threads(input_file, output_file, key, shift, choice, 1);
                break;
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
