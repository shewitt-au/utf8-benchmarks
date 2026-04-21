#include <benchmark/benchmark.h>
#include <string>
#include <iostream>

#include "strings.hpp"
#include "steve.hpp"
#include "axcut.hpp"


static const std::string test_string = make_random_utf8(1024);

static void BM_Steve_strlenUtf8_Traditional_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_Traditional_PoemEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(g_poemEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_Traditional_PoemChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(g_poemChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_Traditional_PoemRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(g_poemRussian);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_PoemEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(g_poemEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_PoemChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(g_poemChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_PoemRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(g_poemRussian);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_PoemEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(g_poemEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_PoemChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(g_poemChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_PoemRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(g_poemRussian);
        benchmark::DoNotOptimize(result);
    }
}

////

static void BM_AxCut_utf8StringLength2_Random(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(test_string);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength2_PoemEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(g_poemEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength2_PoemChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(g_poemChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength2_PoemRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(g_poemRussian);
        benchmark::DoNotOptimize(result);
    }
}



BENCHMARK(BM_Steve_strlenUtf8_Traditional_Random);
BENCHMARK(BM_Steve_strlenUtf8_Traditional_PoemEnglish);
BENCHMARK(BM_Steve_strlenUtf8_Traditional_PoemChinese);
BENCHMARK(BM_Steve_strlenUtf8_Traditional_PoemRussian);

BENCHMARK(BM_Steve_strlenUtf8_Random);
BENCHMARK(BM_Steve_strlenUtf8_PoemEnglish);
BENCHMARK(BM_Steve_strlenUtf8_PoemChinese);
BENCHMARK(BM_Steve_strlenUtf8_PoemRussian);

BENCHMARK(BM_AxCut_utf8StringLength_Random);
BENCHMARK(BM_AxCut_utf8StringLength_PoemEnglish);
BENCHMARK(BM_AxCut_utf8StringLength_PoemChinese);
BENCHMARK(BM_AxCut_utf8StringLength_PoemRussian);

BENCHMARK(BM_AxCut_utf8StringLength2_Random);
BENCHMARK(BM_AxCut_utf8StringLength2_PoemEnglish);
BENCHMARK(BM_AxCut_utf8StringLength2_PoemChinese);
BENCHMARK(BM_AxCut_utf8StringLength2_PoemRussian);

//BENCHMARK_MAIN();

int main(int argc, char** argv) {
    std::cout << "Benchmark random string\n";
    std::cout << "----------------\n";
    std::cout << test_string << '\n';
    std::cout << "----------------\n";
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}

