#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "../compression_algorithm.h"
#include <stdint.h>

typedef struct
{
    uint8_t symbol;
    int32_t frequency;
    int32_t parent;
    int32_t left;
    int32_t right;
} HuffmanNode;

typedef struct
{
    uint8_t symbol;
    int32_t size;
    uint64_t code;
} HuffmanCode;

extern CompressionAlgorithm HuffmanAlgorithm;

#endif // HUFFMAN_H