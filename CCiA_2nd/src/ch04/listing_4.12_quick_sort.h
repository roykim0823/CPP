#pragma once
#include <list>
#include <algorithm>

template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input) {
    if(input.empty())
    //if (input.size() < 2)
    {
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());  // pick the first element for the pivot
                                                          // to avoid the list traversal
    T const &pivot = *result.begin();  // Use reference to avoid the copy

    auto divide_point=std::partition(input.begin(), input.end(),
        [&](T const& t){return t<pivot;});

    // call the sequential_quick_sort recursively
    std::list<T> lower_part;
    // no difference with lower_part.begin()
    lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
    auto new_lower(sequential_quick_sort(std::move(lower_part)));
    auto new_higher(sequential_quick_sort(std::move(input)));

    // merge the lower and higher
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower);
    return result;
}
