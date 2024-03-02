/*
Functionality for reading from and writing to files.

- Basic synchronous read and write functions for handling files as byte streams.
- Asynchronous read/write operations
- Functions to handle different file formats or encodings
- Error handling for file operations
*/

#include <stdio.h>
#include <stdlib.h>

// ----- BELOW THIS LINE: GOOD TO GO -----
ssize_t read_file(const char *path, void **buffer)
{
    // check if file can be opened
    FILE *file = fopen(path, "rb");
    if (file == NULL)
    {
        return -1;
    }

    // get file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // allocate buffer
    *buffer = malloc(file_size);
    if (*buffer == NULL)
    {
        fclose(file);
        return -1;
    }

    // read file into buffer
    size_t bytes_read = fread(*buffer, 1, file_size, file);
    fclose(file);

    // check if all bytes were read
    if (bytes_read != file_size)
    {
        free(*buffer);
        return -1;
    }

    return bytes_read;
}

ssize_t write_file(const char *path, const void *buffer, size_t size)
{
    // check if file can be opened
    FILE *file = fopen(path, "wb");
    if (file == NULL)
    {
        return -1;
    }

    // write buffer to file
    size_t bytes_written = fwrite(buffer, 1, size, file);
    fclose(file);

    // check if all bytes were written
    if (bytes_written != size)
    {
        return -1;
    }

    return bytes_written;
}

void *map_file_to_memory(const char *path, size_t *size)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        return NULL;
    }

    struct stat sb;
    if (fstat(fd, &sb) == -1)
    {
        close(fd);
        return NULL;
    }

    void *mapped = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    if (mapped == MAP_FAILED)
    {
        return NULL;
    }

    *size = sb.st_size;
    return mapped;
}

void unmap_file_from_memory(void *mapped, size_t size)
{
    munmap(mapped, size);
}
// ----- ABOVE THIS LINE: GOOD TO GO -----