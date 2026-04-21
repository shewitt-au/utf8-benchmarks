#include <benchmark/benchmark.h>
#include <string_view>
#include <string>

#include "strings.hpp"

// How fast am I?
size_t strlenUtf8(std::string_view s) {
    size_t count = 0;
    for (unsigned char c : s)
        count += (c & 0xC0) != 0x80;
    return count;
}

// Fixed test string (mix of ASCII + multibyte UTF-8)
static const std::string test_string = make_random_utf8(1024);
//    "Hello © world € 😀 Hello © world € 😀 Hello © world € 😀";

// Benchmark
static void BM_StrlenUtf8_SingleString(benchmark::State& state) {
    for (auto _ : state) {
        auto result = strlenUtf8(test_string);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_StrlenUtf8_SingleString);
BENCHMARK_MAIN();
