#include <benchmark/benchmark.h>
#include <string>
#include <iostream>

#include "strings.hpp"
#include "steve.hpp"
#include "axcut.hpp"


static const std::string test_string = make_random_utf8(1024);
//    "Hello © world € 😀 Hello © world € 😀 Hello © world € 😀";

static void BM_StrlenUtf8_SingleString(benchmark::State& state) {
    for (auto _ : state) {
        auto result = strlenUtf8(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_utf8StringLength_SingleString(benchmark::State& state) {
    for (auto _ : state) {
        auto result = utf8StringLength(test_string);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_StrlenUtf8_SingleString);
BENCHMARK(BM_utf8StringLength_SingleString);

//BENCHMARK_MAIN();

int main(int argc, char** argv) {
    std::cout << "Benchmark string\n";
    std::cout << "----------------\n";
    std::cout << test_string << '\n';
    std::cout << "----------------\n";
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}

