#ifndef MEM_H
#define MEM_H

ssize_t read_memory(const void *src, void *dest, size_t size);
ssize_t write_memory(const void *dest, const void *src, size_t size);

void *map_file_to_memory(const char *path);
void unmap_file_from_memory(void *mapped, size_t size);

#endif // MEM_H