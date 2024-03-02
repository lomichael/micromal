/*
A pool of reusable buffers to minimize overhead of malloc and free operations.

- Basic pool for reusing fixed-size buffers.
- Advanced memory management to adapt pool size based on usage patterns.
- Garbage collection for unused buffers to minimize memory overhead.
*/

#ifndef BUFFER_POOL_H
#define BUFFER_POOL_H

void buffer_pool_init(buffer_pool_t *pool, size_t buffer_size);
buffer_t *buffer_pool_get(buffer_pool_t *pool);
void buffer_pool_return(buffer_pool_t *pool, buffer_t *buf);
void buffer_pool_destroy(buffer_pool_t *pool);
void buffer_pool_resize(buffer_pool_t *pool, size_t new_pool_size);
void buffer_pool_collect_garbage(buffer_pool_t *pool);

#endif // BUFFER_POOL_H