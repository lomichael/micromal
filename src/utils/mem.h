#ifndef MEM_H
#define MEM_H

#include <stdlib.h>

void *safe_malloc(size_t size);
void *safe_realloc(void *ptr, size_t new_size);
void safe_free(void **ptr);

#endif // MEM_H