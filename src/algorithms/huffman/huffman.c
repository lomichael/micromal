#include "../huffman/huffman.h"
#include "../../core/buffer.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_SYMBOLS 256 // max number of symbols representable by a byte
#define MAX_TREE_NODES (2 * MAX_SYMBOLS - 1)

int32_t heapSize;
HuffmanNode heap[MAX_TREE_NODES]; // Ensure proper alignment of the heap array

void huffman_insert_into_heap(HuffmanNode *node)
{
    int32_t i;
    int32_t parent;
    for (i = ++heapSize; i > 1 && node->frequency < heap[parent = i / 2].frequency; i = parent)
    {
        heap[i] = heap[parent];
    }
    heap[i] = *node;
}

HuffmanNode huffman_remove_from_heap()
{
    int32_t i;
    int32_t child;
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

void huffman_build_tree(const int32_t frequencies[], HuffmanCode codes[])
{
    int32_t i = 0;
    int32_t nSymbols = 0;

    printf("Counting symbols...\n");
    for (i = 0; i < MAX_SYMBOLS; i++)
    {
        if (frequencies[i])
            nSymbols++;
    }
    printf("Number of symbols: %d\n", nSymbols);

    printf("Inserting nodes into the heap...\n");
    heapSize = 0;
    for (i = 0; i < MAX_SYMBOLS; i++)
    {
        if (frequencies[i])
        {
            HuffmanNode node = {
                .symbol = (uint8_t)i,
                .frequency = frequencies[i],
                .parent = -1,
                .left = -1,
                .right = -1};
            huffman_insert_into_heap(&node);
        }
    }
    printf("Inserted %d nodes into the heap...\n", i);

    printf("Combining nodes in the heap...\n");
    int32_t trees = nSymbols;
    HuffmanNode nodes[MAX_TREE_NODES];
    for (i = 0; i < nSymbols - 1; i++)
    {
        HuffmanNode *node = &nodes[trees++];
        *node = (HuffmanNode){
            .parent = -1,
            .left = huffman_remove_from_heap().symbol,
            .right = huffman_remove_from_heap().symbol};
        node->frequency = nodes[node->left].frequency + nodes[node->right].frequency;
        nodes[node->left].parent = trees - 1;
        nodes[node->right].parent = trees - 1;
        huffman_insert_into_heap(node);
    }
    printf("Combined nodes in the heap...\n");

    printf("Generating codes for each symbol...\n");
    for (i = 0; i <= MAX_SYMBOLS; i++) // Modify the loop condition to iterate until i <= MAX_SYMBOLS
    {
        if (frequencies[i] > 0)
        {
            uint64_t code = 0;
            int32_t size = 0;
            uint32_t nodeIndex = i;
            while (nodeIndex < trees && nodes[nodeIndex].parent != -1)
            {
                printf("1. Node index: %d\n", nodeIndex);
                printf("1. Node parent: %d\n", nodes[nodeIndex].parent);
                code |= ((uint64_t)(nodes[nodes[nodeIndex].parent].left != nodeIndex) << size++);
                nodeIndex = nodes[nodeIndex].parent;
                printf("2. Node index: %d\n", nodeIndex);
                printf("2. Node parent: %d\n", nodes[nodeIndex].parent);
            }
            codes[i] = (HuffmanCode){
                .symbol = (uint8_t)i,
                .size = size,
                .code = code};
        }

        printf("Generated codes for %d symbols...\n", i);

        if (i == 95 || i == 96)
        {
            printf("i is %d\n", i);
            printf("MAX_SYMBOLS is %d\n", MAX_SYMBOLS);
            printf("frequencies[i] is %d\n", frequencies[i]);
            printf("codes[i].size is %d\n", codes[i].size);
        }
    }
    printf("Finished generating codes for each symbol...\n");
}

void *huffman_compress(const void *input, size_t input_size, void **output, size_t *output_size)
{
    // Step 1: Count byte frequencies in the input
    printf("Input size: %zu\n", input_size);
    printf("Counting byte frequencies in the input...\n");
    int32_t frequencies[MAX_SYMBOLS] = {0};
    for (size_t i = 0; i < input_size; i++)
    {
        frequencies[((uint8_t *)input)[i]]++;
    }

    // Step 2: Build a Huffman tree from the character frequencies
    // Step 3: Generate the Huffman codes for each character
    printf("Building a Huffman tree from the character frequencies...\n");
    HuffmanCode codes[MAX_SYMBOLS] = {0};
    huffman_build_tree(frequencies, codes);

    // Step 4: Encode the input using the Huffman codes
    printf("Encoding the input using the Huffman codes...\n");
    Buffer outputBuffer;
    buffer_init(&outputBuffer);
    printf("1. Output buffer size: %zu\n", outputBuffer.size);

    uint8_t byte = 0; // current byte-to-write
    uint8_t bit = 0;  // current bit position in the byte-to-write
    for (size_t i = 0; i < input_size; i++)
    {
        // current code for the input byte
        HuffmanCode code = codes[((uint8_t *)input)[i]];

        // for each bit in the code, add it to the byte
        for (uint8_t j = 0; j < code.size; j++)
        {
            // left shift the byte and add the next bit of the code
            byte = (byte << 1) | ((code.code >> (code.size - j - 1)) & 1);

            // if the byte is full, write it to the output buffer and reset the byte
            if (++bit == 8)
            {
                buffer_append(&outputBuffer, &byte, 1);
                byte = 0;
                bit = 0;
            }
        }
    }
    printf("2. Output buffer size: %zu\n", outputBuffer.size);

    // if there are any remaining bits in the byte, write it to the output buffer
    if (bit > 0)
    {
        byte <<= (8 - bit);
        buffer_append(&outputBuffer, &byte, 1);
    }
    printf("3. Output buffer size: %zu\n", outputBuffer.size);

    // Step 5: Output the encoded input
    printf("Outputting the encoded input...\n");
    *output = outputBuffer.data;
    *output_size = outputBuffer.size;

    return NULL;
}

void *huffman_decompress(const void *input, size_t input_size, void **output, size_t *output_size)
{
    // Step 1: Extract the Huffman tree and the encoded input from the input
    // Step 2: Decode the input using the Huffman tree
    // Step 3: Output the decoded input

    return NULL;
}

CompressionAlgorithm HuffmanAlgorithm = {
    .compress = huffman_compress,
    .decompress = huffman_decompress};