#include "../core/buffer.h"
#include "../utils/mem.h"
#include <stdlib.h>
#include <string.h>

// Function to initialize a buffer
void buffer_init(Buffer *buffer)
{
    buffer->data = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}

// Function to allocate a buffer
void buffer_alloc(Buffer *buffer, size_t size)
{
    buffer->data = safe_malloc(size);
    buffer->size = size;
    buffer->capacity = size;
}

// Function to free the buffer
void buffer_free(Buffer *buffer)
{

    free(buffer->data);
    buffer->data = NULL;
    buffer->size = 0;
    buffer->capacity = 0;
}

// Function to resize the buffer
void buffer_resize(Buffer *buffer, size_t new_size)
{
    if (new_size > buffer->capacity)
    {
        buffer->capacity = new_size;
        buffer->data = safe_realloc(buffer->data, buffer->capacity);
    }
    buffer->size = new_size;
}

// Function to append data to the buffer
void buffer_append(Buffer *buffer, const void *data, size_t size)
{
    size_t new_size = buffer->size + size;
    if (new_size > buffer->capacity)
    {
        buffer->capacity = new_size;
        buffer->data = safe_realloc(buffer->data, buffer->capacity);
    }
    memcpy(buffer->data + buffer->size, data, size);
    buffer->size = new_size;
}