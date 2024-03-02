/*
Dynamically resizable buffer supporting append and read operations.

- Implementation of a dynamic buffer that can grow and shrink as needed.
- Thread-safe operations for reading and writing to the buffer to ensure safe use across threads.
- Optimization for frequent resize operations to minimize memory overhead.
*/

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

// ----- BELOW THIS LINE: GOOD TO GO -----

struct buffer_t
{
    char *data;
    size_t size;
    size_t capacity;
    pthread_mutex_t mutex;
};

void buffer_init(buffer_t *buf)
{
    buf->data = NULL;
    buf->size = 0;
    buf->capacity = 0;
    pthread_mutex_init(&buf->mutex, NULL);
}

void buffer_resize(buffer_t *buf, size_t new_size)
{
    if (new_size > buf->capacity)
    {
        size_t new_capacity = new_size * 2;
        char *new_data = realloc(buf->data, new_capacity);
        if (new_data == NULL)
        {
            exit(1); // simple strategy of handling memory allocation failure is to exit the program
        }
        buf->data = new_data;
        buf->capacity = new_capacity;
    }
    buf->size = new_size;
}

void buffer_append(buffer_t *buf, const void *data, size_t data_size)
{
    pthread_mutex_lock(&buf->mutex);
    if (buf->size + data_size > buf->capacity)
    {
        buffer_resize(buf, buf->size + data_size);
    }
    memcpy(buf->data + buf->size, data, data_size);
    buf->size += data_size;
    pthread_mutex_unlock(&buf->mutex);
}

void buffer_free(buffer_t *buf)
{
    free(buf->data);
    pthread_mutex_destroy(&buf->mutex);
    buf->data = NULL;
    buf->size = 0;
    buf->capacity = 0;
}

// ----- ABOVE THIS LINE: GOOD TO GO -----