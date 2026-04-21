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

static void BM_Steve_strlenUtf8_Traditional_ShortStringEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(g_shortStringEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_Traditional_ShortStringChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(g_shortStringChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_Traditional_ShortStringRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8_Traditional(g_shortStringRussian);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_ShortStringEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(g_shortStringEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_ShortStringChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(g_shortStringChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_Steve_strlenUtf8_ShortStringRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = steve::strlenUtf8(g_shortStringRussian);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_ShortStringEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(g_shortStringEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_ShortStringChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(g_shortStringChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength_ShortStringRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength(g_shortStringRussian);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength2_ShortStringEnglish(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(g_shortStringEnglish);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength2_ShortStringChinese(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(g_shortStringChinese);
        benchmark::DoNotOptimize(result);
    }
}

static void BM_AxCut_utf8StringLength2_ShortStringRussian(benchmark::State& state) {
    for (auto _ : state) {
        auto result = axcut::utf8StringLength2(g_shortStringRussian);
        benchmark::DoNotOptimize(result);
    }
}

// Random
BENCHMARK(BM_Steve_strlenUtf8_Traditional_Random)
    ->Name("Random/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_Random)
    ->Name("Random/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_Random)
    ->Name("Random/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_Random)
    ->Name("Random/AxCut/2");

// Poem English
BENCHMARK(BM_Steve_strlenUtf8_Traditional_PoemEnglish)
    ->Name("Poem/English/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_PoemEnglish)
    ->Name("Poem/English/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_PoemEnglish)
    ->Name("Poem/English/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_PoemEnglish)
    ->Name("Poem/English/AxCut/2");

// Poem Chinese
BENCHMARK(BM_Steve_strlenUtf8_Traditional_PoemChinese)
    ->Name("Poem/Chinese/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_PoemChinese)
    ->Name("Poem/Chinese/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_PoemChinese)
    ->Name("Poem/Chinese/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_PoemChinese)
    ->Name("Poem/Chinese/AxCut/2");

// Poem Russian
BENCHMARK(BM_Steve_strlenUtf8_Traditional_PoemRussian)
    ->Name("Poem/Russian/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_PoemRussian)
    ->Name("Poem/Russian/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_PoemRussian)
    ->Name("Poem/Russian/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_PoemRussian)
    ->Name("Poem/Russian/AxCut/2");

// Short string English
BENCHMARK(BM_Steve_strlenUtf8_Traditional_ShortStringEnglish)
    ->Name("Short-string/English/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_ShortStringEnglish)
    ->Name("Short-string/English/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_ShortStringEnglish)
    ->Name("Short-string/English/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_ShortStringEnglish)
    ->Name("Short-string/English/AxCut/2");

// Short string Chinese
BENCHMARK(BM_Steve_strlenUtf8_Traditional_ShortStringChinese)
    ->Name("Short-string/Chinese/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_ShortStringChinese)
    ->Name("Short-string/Chinese/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_ShortStringChinese)
    ->Name("Short-string/Chinese/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_ShortStringChinese)
    ->Name("Short-string/Chinese/AxCut/2");

// Short string Russian
BENCHMARK(BM_Steve_strlenUtf8_Traditional_ShortStringRussian)
    ->Name("Short-string/Russian/Steve/Traditional");

BENCHMARK(BM_Steve_strlenUtf8_ShortStringRussian)
    ->Name("Short-string/Russian/Steve/Optimized");

BENCHMARK(BM_AxCut_utf8StringLength_ShortStringRussian)
    ->Name("Short-string/Russian/AxCut/1");

BENCHMARK(BM_AxCut_utf8StringLength2_ShortStringRussian)
    ->Name("Short-string/Russian/AxCut/2");

//BENCHMARK_MAIN();

int main(int argc, char** argv) {
    std::cout << "Benchmark random string\n";
    std::cout << "----------------\n";
    std::cout << test_string << '\n';
    std::cout << "----------------\n";
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}
