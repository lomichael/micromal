#ifndef COMPRESSION_ALGORITHM_H
#define COMPRESSION_ALGORITHM_H

#include <stddef.h>

// A structure for the compression interface
typedef struct
{
    void *(*compress)(const void *input, size_t input_size, void **output, size_t *output_size);
    void *(*decompress)(const void *input, size_t input_size, void **output, size_t *output_size);
} CompressionAlgorithm;

#endif // COMPRESSION_ALGORITHM_H