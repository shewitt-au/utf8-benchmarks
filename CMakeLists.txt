cmake_minimum_required(VERSION 3.16)
project(bench_project CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG main
)

# Disable benchmark's own tests (speeds up build massively)
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(benchmark)

add_executable(bench bench.cpp strings.cpp steve.cpp axcut.cpp)

target_link_libraries(bench PRIVATE benchmark::benchmark)

# Windows-specific fix (optional but helps MSVC builds)
if (MSVC)
    target_compile_options(bench PRIVATE /O2)
else()
    target_compile_options(bench PRIVATE -O3)
endif()