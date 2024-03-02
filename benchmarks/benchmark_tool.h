/*
Tool for running the library against predefined benchmarks and outputting performance metrics.

- Measure compression ration and speeed for a dataset.
- Comprehensive benchmarking suite capable of testing multiple algorithms across different datasets.
- Automated performance regression testing to ensure that changes to the library do not degrade performance.
- Detailed reporting of performance metrics and statistical analysis of benchmark results.
*/

#ifndef BENCHMARK_H
#define BENCHMARK_H

void benchmark_algorithm(compression_algorithm_t, const char *dataset_path);
void run_benchmarks(const char *config_file);
void compare_algorithm_performance(compression_algorithm_t algorithm1, compression_algorithm_t algorithm2, const char *dataset_path);
void report_benchmark_results(const benchmark_result_t *results, size_t count);

#endif // BENCHMARK_H