#ifndef CORE_IO_H
#define CORE_IO_H

#include <stddef.h>

ssize_t read_file_to_buffer(const char *file_path, void **buffer);
ssize_t write_buffer_to_file(const char *file_path, const void *buffer, size_t size);

#endif // CORE_IO_H