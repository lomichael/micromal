/*
Functions to initialize the library, set compression options, and compress and decompress data.

- Functions to compress and decompress data with an algorithm.
- Extensible API that allows selecting different compression algorithms and options.
- High-level abstractions for stream-based processing, allowing for efficient processing of large datasets.
- Error handling and detailed status reporting.
*/

#ifndef API_H
#define API_H

#include <stddef.h>

int compress_data(const void *input, size_t input_size, void **output, size_t *output_size);
int decompress_data(const void *input, size_t input_size, void **output, size_t *output_size);

int initialize_compression_library(void);
int set_compression_algorithm(compression_algorithm_t algorithm);
int compress_stream(stream_t *input, stream_t *output);
int decompress_stream(stream_t *input, stream_t *output);
int finalize_compression_library(void);

#endif // API_H