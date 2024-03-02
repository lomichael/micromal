/*
Functions for automated testing with different datasets, comparing compression ratios and speed.

- Hard-coded tests for a couple of key datasets to verify library performance.
- Extensive test suite covering a wide range of datatypes and file sizes.
- Automatic comparison of output against known good output to verify correctness.
- Performance benchmarking against other compression libraries.
*/

#ifndef BENCHMARKS_H
#define BENCHMARKS_H

void test_compression(const char *input_path, const char *output_path);
void test_decompression(const char *input_path, const char *output_path);
void test_all_algorithms(const char *dataset_dir);
void verify_compression_correctness(const char *input_path, const char *output_path);
void measure_compression_ratio(const char *input_path, const char *output_path);

#endif // BENCHMARKS_H