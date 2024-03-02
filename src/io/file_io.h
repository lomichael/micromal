/*
Functionality for reading from and writing to files.

- Basic synchronous read and write functions for handling files as byte streams.
- Asynchronous read/write operations
- Functions to handle different file formats or encodings
- Error handling for file operations
*/

#ifndef FILE_IO_H
#define FILE_IO_H

#include <sys/types.h>
#include <stdlib.h>

// ----- BELOW THIS LINE: GOOD TO GO -----

// Basic synchronous file I/O
ssize_t read_file(const char *path, void **buffer);
ssize_t write_file(const char *path, const void *buffer, size_t size);

// Asynchronous file I/O
ssize_t async_read_file(const char *path, void **buffer);
ssize_t async_write_file(const char *path, const void *buffer, size_t size);

// ----- ABOVE THIS LINE: GOOD TO GO -----

#endif // FILE_IO_H