# CS180-FinalProject_LeirePablo
Final project for CS180 by Leire Camacho and Pablo Garbizu

# Project Proposal Summary
The goal of this project is to develop a versatile and user-friendly packaging tool that allows
users to securely encrypt and decrypt files. This tool will enable users to select one or more
files, bundle them together, and apply encryption to safeguard their contents. Users will have
the flexibility to choose from multiple encryption methods, allowing them to select the
algorithm that best fits their security needs and performance requirements.

In addition to encryption, the tool will provide decryption functionality, enabling secure
communication between users by allowing them to share encrypted file bundles and decrypt
them back. By integrating multithreading, the tool will optimize encryption and decryption
speed for larger files.

# Information for the User
These will be the main three encrypting methods:

  - **XOR Cipher**: A simple symmetric encryption technique that XORs each byte of data with a key. Although not very secure, it serves as an introduction to encryption basics.

  - **BitShift (Dummy Encryption)**: A simple, symmetric encryption method that shifts each byte’s bits left or right by a set number. Optionally, a key can be applied with XOR for added obfuscation.

  - **RSA**: An asymmetric encryption algorithm that uses a pair of public and private keys. Commonly used to encrypt small data (like keys), the user will provide both keys.

The package tool will consist of a .exe that will first ask what function the user wants to use,
that is; encrypting or decrypting. After providing the functionality to be used, the .exe will
ask the user for the file to decrypt or if the wanted action is to encrypt, the user would be able
to provide more than one file name if applicable. The file names will be given via the command line along with the key. The .exe will place the output .txt file in the same folder the .exe is located.

# Implementation

1. Chunk Reading and Thread Dispatching
    To begin the encryption process, the file is read in chunks, where each chunk represents a segment of data that can be processed independently. After reading a chunk, the program dispatches it to a separate thread, allowing each thread to handle the encryption of its assigned data. Along with the chunk, each thread receives essential information, such as a pointer to the chunk’s starting position, the encryption key, and any other necessary parameters.

2. Encryption in Threads
    Once each thread receives its data chunk and parameters, it proceeds with the encryption algorithm on its assigned data independently of the others. Each thread operates on its data block without needing coordination with other threads.

3. Collect & Write Output
    After each thread finishes encrypting its assigned chunk, the encrypted chunks are gathered to form the complete encrypted file. To maintain the correct sequence of data, the program ensures that chunks are written to the output file in the original order, regardless of the order in which threads complete.

# References
GitHub. (February 21th of 2024). BitShift Cipher.
https://github.com/Cryptools/BitShiftCipher/blob/master/README.md
Wikipedia. (October 24th of 2024). RSA (cryptosystem).
https://en.wikipedia.org/wiki/RSA_(cryptosystem)
Wikipedia. (November 2nd of 2024). Modular Arithmetic.
https://en.wikipedia.org/wiki/Modular_arithmetic
Wikipedia. (November 8th of 2024). Bitwise Operation.
https://en.wikipedia.org/wiki/Bitwise_operation#Bit_shifts
Wikipedia. (September 4th of 2024). OpenSSL.
https://es.wikipedia.org/wiki/OpenSSL