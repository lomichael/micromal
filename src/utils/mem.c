#include "../utils/mem.h"
#include "../utils/log.h"

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (!ptr)
    {
        log_message(LOG_ERROR, "Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *safe_realloc(void *ptr, size_t new_size)
{
    void *new_ptr = realloc(ptr, new_size);
    if (!new_ptr)
    {
        log_message(LOG_ERROR, "Failed to reallocate memory");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

void safe_free(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}
