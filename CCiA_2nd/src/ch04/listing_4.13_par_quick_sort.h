#pragma once
#include <list>
#include <algorithm>
#include <future>

template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
//std::list<T> parallel_quick_sort(std::list<T>& input)
{
    if(input.empty())
    //if (input.size() < 2)
    {
        return input;
    }

    // select the pivot value
    std::list<T> result;
    result.splice(result.begin(),input,input.begin());
    T const &pivot = *result.begin();
    auto divide_point=std::partition(input.begin(),input.end(),
        [&](T const& t){return t<pivot;});

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

    std::future<std::list<T> > new_lower(
    std::async(&parallel_quick_sort<T>, std::move(lower_part)));  // std::move lose data
    // std::async(&parallel_quick_sort<T>, std::ref(lower_part)));  // Use std::ref to keep the all data, change with the arg->ref
    auto new_higher(parallel_quick_sort(input));


    // merge the lower and higher
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower.get());

    return result;  // WRONG!!: result.size() is much smaller than the original input.size()
}
