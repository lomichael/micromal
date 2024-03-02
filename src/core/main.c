#include "../algorithms/huffman/huffman.h"
#include "../../tests/benchmarks/benchmark.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 4)
    {
        printf("Usage: %s <algorithm> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Parse the algorithm argument
    CompressionAlgorithm* algorithm;
    if (strcmp(argv[1], "huffman") == 0)
    {
        // Pass the Huffman algorithm to the benchmark function
        algorithm = &HuffmanAlgorithm;
    }
    else
    {
        printf("Invalid algorithm: %s\n", argv[1]);
        return 1;
    }

    // Run the benchmark
    benchmark(algorithm, argv[2], argv[3]);

    return 0;
}