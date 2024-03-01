#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stddef.h>

// A structure for the compression statistics
typedef struct
{
    size_t original_size;
    size_t compressed_size;
    double compression_ratio;
    double time_taken;
} CompressionStats;

typedef enum
{
    SUCCESS,
    FILE_ERROR,
    MEMORY_ERROR,
    COMPRESSION_ERROR,
    DECOMPRESSION_ERROR
} ErrorCode;

#endif // STRUCTURES_H