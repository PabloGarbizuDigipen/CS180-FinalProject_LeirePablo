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
//#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
