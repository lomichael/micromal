#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "algorithms/compression_algorithm.h"
#include <stdint.h>

typedef struct
{
    uint8_t symbol;
    int frequency;
    uint8_t parent;
    uint8_t left;
    uint8_t right;
} HuffmanNode;

typedef struct
{
    uint8_t symbol;
    uint8_t code_length;
    uint32_t code;
} HuffmanCode;

void huffman_compress(const void *input, size_t input_size, void **output, size_t *output_size);
void huffman_decompress(const void *input, size_t input_size, void **output, size_t *output_size);

CompressionAlgorithm HuffmanAlgorithm = {
    .compress = huffman_compress,
    .decompress = huffman_decompress};

#endif // HUFFMAN_H