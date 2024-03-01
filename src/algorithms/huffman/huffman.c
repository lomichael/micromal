#include "algorithms/huffman/huffman.h"
#include "core/buffer.h"
#include <stdint.h>
#include <string.h>

#define MAX_SYMBOLS 256 // max number of symbols representable by a byte
#define MAX_TREE_NODES (2 * MAX_SYMBOLS - 1)

uint8_t heapSize;
HuffmanNode heap[MAX_TREE_NODES];

void huffman_insert_into_heap(HuffmanNode *node)
{
    uint8_t i;
    uint8_t parent;
    for (i = ++heapSize; i > 1 && node->frequency < heap[parent = i / 2].frequency; i = parent)
    {
        heap[i] = heap[parent];
    }
    heap[i] = *node;
}

HuffmanNode huffman_remove_from_heap(HuffmanNode *node)
{
    uint8_t i;
    uint8_t child;
    HuffmanNode min = heap[1];
    HuffmanNode last = heap[heapSize--];
    for (i = 1; (child = i * 2) <= heapSize; i = child)
    {
        if (child < heapSize && heap[child + 1].frequency < heap[child].frequency)
        {
            ++child;
        }
        if (last.frequency <= heap[child].frequency)
        {
            break;
        }
        heap[i] = heap[child];
    }
    heap[i] = last;
    return min;
}

void huffman_build_tree(uint8_t frequencies[], HuffmanCode codes[])
{
    uint8_t i = 0;
    uint8_t nSymbols = 0;

    for (i = 0; i < MAX_SYMBOLS; i++)
    {
        if (frequencies[i] > 0)
        {
            HuffmanNode node = {
                .symbol = i,
                .frequency = frequencies[i],
                .parent = 0,
                .left = 0,
                .right = 0};
            huffman_insert_into_heap(&node);
            nSymbols++;
        }
    }

    uint8_t trees = nSymbols;
    HuffmanNode nodes[MAX_TREE_NODES];
    for (i = 0; i < nSymbols; i++)
    {
        HuffmanNode *node = &nodes[trees++];
        *node = (HuffmanNode){
            .parent = 0,
            .left = huffman_remove_from_heap(node).symbol,
            .right = huffman_remove_from_heap(node).symbol};
        node->frequency = heap[node->left].frequency + heap[node->right].frequency;
        huffman_insert_into_heap(node);
    }

    for (i = 0; i < nSymbols; i++)
    {
        uint8_t length = 0;
        uint32_t code = 0;
        uint8_t symbol = i;
        for (uint8_t current = symbol; (current = nodes[current].parent) != 0; length++)
        {
            code = (code << 1) | ((nodes[current].right == symbol) ? 1 : 0);
        }
        codes[symbol] = (HuffmanCode){
            .symbol = symbol,
            .code_length = length,
            .code = code};
    }
}

void huffman_compress(const void *input, size_t input_size, void **output, size_t *output_size)
{
    // Step 1: Count byte frequencies in the input
    uint8_t frequencies[MAX_SYMBOLS] = {0};
    for (size_t i = 0; i < input_size; i++)
    {
        frequencies[((uint8_t *)input)[i]]++;
    }

    // Step 2: Build a Huffman tree from the character frequencies
    // Step 3: Generate the Huffman codes for each character
    HuffmanCode codes[MAX_SYMBOLS] = {0};
    huffman_build_tree(frequencies, codes);

    // Step 4: Encode the input using the Huffman codes
    Buffer outputBuffer;
    buffer_alloc(&outputBuffer, input_size);

    uint8_t byte = 0; // current byte-to-write
    uint8_t bit = 0;  // current bit position in the byte-to-write
    for (size_t i = 0; i < input_size; i++)
    {
        // current code for the input byte
        HuffmanCode code = codes[((uint8_t *)input)[i]];

        // for each bit in the code, add it to the byte
        for (uint8_t j = 0; j < code.code_length; j++)
        {
            // left shift the byte and add the next bit of the code
            byte = (byte << 1) | ((code.code >> (code.code_length - j - 1)) & 1);

            // if the byte is full, write it to the output buffer and reset the byte
            if (++bit == 8)
            {
                buffer_write(&outputBuffer, &byte, 1);
                byte = 0;
                bit = 0;
            }
        }
    }

    // if there are any remaining bits in the byte, write it to the output buffer
    if (bit > 0)
    {
        byte <<= (8 - bit);
        buffer_copy(&outputBuffer, &byte, 1);
    }

    // Step 5: Package the Huffman tree and the encoded input into the output
    *output = outputBuffer.data;
    *output_size = outputBuffer.size;
}

void huffman_decompress(const void *input, size_t input_size, void **output, size_t *output_size)
{
    // Step 1: Extract the Huffman tree and the encoded input from the input
    // Step 2: Decode the input using the Huffman tree
    // Step 3: Output the decoded input
}