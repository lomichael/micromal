#include <time.h>
#include "src/algorithms/huffman/huffman.h"
#include "src/utils/io.h"
#include "src/utils/mem.h"

// function benchmark() takes an algorithm and input_file and output_file as arguments
void benchmark(CompressionAlgorithm compression_algorithm, const char *input_filename, const char *output_filename)
{
    // Read the input file into memory
    void *input_data;
    size_t input_size = read_file_to_buffer(input_filename, &input_data);

    // Prepare the output buffer
    void *compressed_data = NULL;
    size_t compressed_size = 0;

    // Compress the input data
    clock_t start = clock();
    compression_algorithm.compress(input_data, input_size, &compressed_data, &compressed_size);
    clock_t end = clock();

    // Calculate compression time and compression ratio
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    double compression_ratio = (double)input_size / compressed_size;

    // Calculate nanoseconds per byte
    double ns_per_byte = (time_taken * 1e9) / input_size;

    // Calculate bits per character
    double bits_per_char = (8 * compressed_size) / input_size;

    // Write the compressed data to the output file
    size_t output_size = write_buffer_to_file(output_filename, compressed_data, compressed_size);

    // Output the benchmark results
    printf("Original size: %zu bytes\n", input_size);
    printf("Compressed size: %zu bytes\n", output_size);
    printf("Compression ratio: %.2f\n", compression_ratio);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Bits per character: %.2f\n", bits_per_char);
    printf("Nanoseconds per byte: %.2f\n", ns_per_byte);

    // Clean up
    safe_free(input_data);
    safe_free(compressed_data);
}