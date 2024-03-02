/*
Tool for running the library against predefined benchmarks and outputting performance metrics.

- Measure compression ration and speeed for a dataset.
- Comprehensive benchmarking suite capable of testing multiple algorithms across different datasets.
- Automated performance regression testing to ensure that changes to the library do not degrade performance.
- Detailed reporting of performance metrics and statistical analysis of benchmark results.
*/

#include <stdio.h>
#include <time.h>
#include "buffer.h"
#include "api.h"

// ----- BELOW: DUMMY IMPLEMENTATION -----

void bencmark_algorithm(const char *input_path)
{
    buffer_t input, compressed;
    buffer_init(&input);
    buffer_init(&compressed);

    ssize_t input_size = read_file(input_path, &input.data);

    clock_t start = clock();
    compress_data(&input, input_size, &compressed.data, &compressed.size);
    clock_t end = clock();

    void *decompressed = NULL;
    size_t decompressed_size = 0;

    clock_t start2 = clock();
    decompress(compressed, compressed.size, &decompressed, &decompressed_size);
    clock_t end2 = clock();

    double compress_time = (double)(end - start) / CLOCKS_PER_SEC;
    double decompress_time = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("Compression time: %f seconds\n", compress_time);
    printf("Decompression time: %f seconds\n", decompress_time);
    printf("Compression ratio: %.2f\n", (double)compressed.size / input_size);

    buffer_free(&input);
    buffer_free(&compressed);
}

// ----- ABOVE: DUMMY IMPLEMENTATION -----