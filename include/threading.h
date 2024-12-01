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
#include <stdbool.h>

void process_file_with_threads(const char *input_file, const char *output_file, const char *key, int shift, int method, bool decrypt);

#endif // THREADING_H
