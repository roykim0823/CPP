#include <vector>
#include <iostream>
#include "include/common.h"
#include "listing_8.11_parallel_partial_sum.h"

void test_seq_partial_sum() {
    std::vector<int> ints(10);
    std::vector<int> outs(10);

    for(size_t i=0; i<ints.size(); ++i) {
        ints[i] = i;
    }
    seq_partial_sum(ints.begin(), ints.end(), outs.begin());

    
    for(size_t i=0; i<ints.size(); ++i) {
        std::cout << outs[i] << " ";
    }
    std::cout << std::endl;
}

#include <iostream>
#include <chrono>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <execution>

const size_t testSize = 1'000000;

int main()
{
    std::vector<int> ints(testSize);
    std::vector<int> outs(testSize);
    for (auto& i : ints) {
        i = 1;
    }

    //sequential implementation
    auto startTime = high_resolution_clock::now();
    seq_partial_sum(ints.cbegin(), ints.cend(), outs.begin());
    auto endTime = high_resolution_clock::now();
    print_results("seq_partial_sum scan", startTime, endTime);

    //sequential implementation
    startTime = high_resolution_clock::now();
    std::inclusive_scan(ints.cbegin(), ints.cend(), outs.begin());
    endTime = high_resolution_clock::now();
    print_results("sequential scan", startTime, endTime);

    // C++17 parallel implementation
    startTime = high_resolution_clock::now();
    std::inclusive_scan(std::execution::par,ints.cbegin(), ints.cend(), outs.begin());
    endTime = high_resolution_clock::now();
    print_results("parallel scan", startTime, endTime);

    // Our parallel implementation
    startTime = high_resolution_clock::now();
    parallel_partial_sum(ints.begin(), ints.end());
    endTime = high_resolution_clock::now();
    print_results("parallel scan manual", startTime, endTime);
   
    return 0;
}