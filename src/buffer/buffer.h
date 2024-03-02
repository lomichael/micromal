/*
Dynamically resizable buffer supporting append and read operations.

- Implementation of a dynamic buffer that can grow and shrink as needed.
- Thread-safe operations for reading and writing to the buffer to ensure safe use across threads.
- Optimization for frequent resize operations to minimize memory overhead.
*/

#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>

typedef struct buffer_t buffer_t;

void buffer_init(buffer_t *buf);
void buffer_resize(buffer_t *buf, size_t new_size);
void buffer_append(buffer_t *buf, const void *data, size_t data_size);
void buffer_free(buffer_t *buf);

void buffer_reset(buffer_t *buf);
ssize_t buffer_read_from_file(buffer_t *buf, const char *path);
ssize_t buffer_write_to_file(const buffer_t *buf, const char *path);

#endif // BUFFER_H