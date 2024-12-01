#pragma once
#include <list>
#include <algorithm>

template<typename T>
std::list<T> sequential_quick_sort(std::list<T>& input)
{
    if(input.empty())
    //if (input.size() < 2)
    {
        return input;
    }

    // select the pivot value
    std::list<T> result;
    result.splice(result.begin(),input,input.begin());
    T const& pivot=*result.begin();
    auto divide_point=std::partition(input.begin(),input.end(),
        [&](T const& t){return t<pivot;});
    
    // call the sequential_quick_sort recursively
    std::list<T> lower_part;
    // no difference with lower_part.begin()
    lower_part.splice(lower_part.end(), input,input.begin(), divide_point);
    //auto new_lower(sequential_quick_sort(std::move(lower_part)));
    //auto new_higher(sequential_quick_sort(std::move(input)));
    auto new_lower(sequential_quick_sort(lower_part));
    auto new_higher(sequential_quick_sort(input));

    // merge the lower and higher
    result.splice(result.end(),new_higher);
    result.splice(result.begin(),new_lower);
    return result;
}

