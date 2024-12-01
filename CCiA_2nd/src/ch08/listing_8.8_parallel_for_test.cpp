#include <stddef.h>
#include <stdio.h>
#include <algorithm>
#include <random>
#include <ratio>
#include <vector>
#include <chrono>

#include <execution>

#include "listing_8.7_parallel_for_each.h"
#include "listing_8.8_parallel_for_each_async.h"

using std::random_device;
using std::sort;
using std::vector;

const size_t testSize = 1000;
const int iterationCount = 4;

int main() {
    random_device rd;

    // generate some random doubles:
    printf("Testing with %zu doubles...\n", testSize);
    std::vector<int> ints(testSize, 1);

    auto long_function = [] (const int& n) {
        int sum = 0;
        for (auto i=0; i<100000; ++i) {
            sum += 1*(i-499);
        }
    };


    // time how long it takes to sort them:
    for (int i = 0; i < iterationCount; ++i)
    {
        const auto startTime = high_resolution_clock::now();
        std::for_each(ints.cbegin(), ints.cend(), long_function);
        const auto endTime = high_resolution_clock::now();
        print_results("std::for_each: ", startTime, endTime);
    }

    // time how long it takes to sort them:
    for (int i = 0; i < iterationCount; ++i)
    {
        const auto startTime = high_resolution_clock::now();
        std::for_each(std::execution::seq, ints.cbegin(), ints.cend(), long_function);
        const auto endTime = high_resolution_clock::now();
        print_results("std::for_each(seq): ", startTime, endTime);
    }

    for (int i = 0; i < iterationCount; ++i)
    {
        const auto startTime = high_resolution_clock::now();
        std::for_each(std::execution::par, ints.cbegin(), ints.cend(), long_function);
        const auto endTime = high_resolution_clock::now();
        print_results("std::for_each(par): ", startTime, endTime);
    }

    for (int i = 0; i < iterationCount; ++i)
    {
        const auto startTime = high_resolution_clock::now();
        parallel_for_each(ints.cbegin(), ints.cend(), long_function);
        const auto endTime = high_resolution_clock::now();
        print_results("parallel_for_each: ", startTime, endTime);
    }

    for (int i = 0; i < iterationCount; ++i)
    {
        const auto startTime = high_resolution_clock::now();
        parallel_for_each_async(ints.cbegin(), ints.cend(), long_function);
        const auto endTime = high_resolution_clock::now();
        print_results("parallel_for_each_async: ", startTime, endTime);
    }
}
