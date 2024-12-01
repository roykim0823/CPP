#include <stddef.h>
#include <stdio.h>
#include <algorithm>
#include <random>
#include <ratio>
#include <vector>
#include <chrono>

#include <execution>

#include "listing_4.12_quick_sort.h"
#include "listing_4.13_par_quick_sort.h"

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::milli;
using std::random_device;
using std::sort;
using std::vector;

const size_t testSize = 1'000'00;
const int iterationCount = 4;

void print_results(const char* const tag, const std::list<double>& sorted,
    high_resolution_clock::time_point startTime,
    high_resolution_clock::time_point endTime) {
    printf("Size: %d %s: Lowest: %g Highest: %g Time: %fms\n", sorted.size(), tag, sorted.front(),
        sorted.back(),
        duration_cast<duration<double, milli>>(endTime - startTime).count());
}

int main() {
    random_device rd;

    // generate some random doubles:
    printf("Testing with %zu doubles...\n", testSize);
    std::list<double> doubles(testSize);
    for (auto& d : doubles) {
        d = static_cast<double>(rd());
    }

    // time how long it takes to sort them:
    for (int i = 0; i < iterationCount; ++i)
    {
        std::list<double> sorted(doubles);
        const auto startTime = high_resolution_clock::now();
        sorted.sort();
        const auto endTime = high_resolution_clock::now();
        print_results("std::sort(): ", sorted, startTime, endTime);
    }

    // time how long it takes to sort them:
    for (int i = 0; i < iterationCount; ++i)
    {
        std::list<double> sorted(doubles);
        const auto startTime = high_resolution_clock::now();
        sorted = sequential_quick_sort(sorted);
        const auto endTime = high_resolution_clock::now();
        print_results("Seq QuickSort: ", sorted, startTime, endTime);
    }

    for (int i = 0; i < iterationCount; ++i)
    {
        std::list<double> sorted(doubles);
        const auto startTime = high_resolution_clock::now();
        sorted = parallel_quick_sort(sorted);
        const auto endTime = high_resolution_clock::now();
        print_results("Par QuickSort: ", sorted, startTime, endTime);
    }
}
