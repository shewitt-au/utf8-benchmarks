#include <benchmark/benchmark.h>
#include <string>
#include <iostream>

#include "strings.hpp"
#include "steve.hpp"
#include "axcut.hpp"


static const std::string test_string = make_random_utf8(1024);

static void BM_Steve_strlenUtf8_Traditional(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_StrlenUtf8(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(test_string);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_Steve_strlenUtf8_Traditional);
BENCHMARK(BM_Steve_StrlenUtf8);
BENCHMARK(BM_AxCut_utf8StringLength);

//BENCHMARK_MAIN();

int main(int argc, char** argv) {
    std::cout << "Benchmark string\n";
    std::cout << "----------------\n";
    std::cout << test_string << '\n';
    std::cout << "----------------\n";
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}

