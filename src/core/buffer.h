#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>
#include <stdint.h>

typedef struct
{
    uint8_t *data;
    size_t size;
    size_t capacity;
} Buffer;

void buffer_init(Buffer *buffer);
void buffer_alloc(Buffer *buffer, size_t size);
void buffer_free(Buffer *buffer);
void buffer_resize(Buffer *buffer, size_t new_size);
void buffer_write(Buffer *buffer, const void *data, size_t size);
void buffer_append(Buffer *buffer, const void *data, size_t size);

#endif // BUFFER_H