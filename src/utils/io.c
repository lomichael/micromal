#include "../utils/io.h"
#include "../utils/mem.h"
#include <stdio.h>
#include <stdlib.h>

size_t read_file_to_buffer(const char *file_path, void **buffer)
{
    FILE *file = fopen(file_path, "rb");
    if (!file)
        return -1;

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *buffer = safe_malloc(file_size);
    if (!*buffer)
    {
        fclose(file);
        return -1;
    }

    ssize_t read_size = fread(*buffer, 1, file_size, file);
    fclose(file);

    return read_size == file_size ? read_size : -1;
}

size_t write_buffer_to_file(const char *file_path, const void *buffer, size_t size)
{
    FILE *file = fopen(file_path, "wb");
    if (!file)
        return -1;

    ssize_t write_size = fwrite(buffer, 1, size, file);
    fclose(file);

    return write_size == size ? write_size : -1;
}