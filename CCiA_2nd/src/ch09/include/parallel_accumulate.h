#pragma once
#include <vector>
#include <future>
#include <numeric>
#include <thread>
#include "simple_thread_pool.h"

// Listing 9.3 parallel_accumulate using a thread pool with waitable tasks
template<typename Iterator, typename T>
struct accumulate_block
{
	T operator()(Iterator first, Iterator last)
	{
		T value = std::accumulate(first, last, T());
		printf(" %u - %d  \n", std::this_thread::get_id(), value);
		return value;
	}
};


// From listing_9.3.cpp
template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{
    unsigned long const length=std::distance(first,last);

    if(!length)
        return init;

    unsigned long const block_size=25;
    unsigned long const num_blocks=(length+block_size-1)/block_size;

    std::vector<std::future<T> > futures(num_blocks-1);
    ThreadPoolWait<function_wrapper> pool;

    Iterator block_start=first;
    for(unsigned long i=0;i<(num_blocks-1);++i)
    {
        Iterator block_end=block_start;
        std::advance(block_end,block_size);
        //futures[i] = pool.submit([=] { accumulate_block<Iterator,T>() (block_start, block_end);} );
        futures[i] = pool.submit(std::bind(accumulate_block<Iterator, T>(), block_start, block_end));
        block_start=block_end;
    }
    T last_result=accumulate_block<int*, int>()(block_start,last);
    T result=init;
    for(unsigned long i=0;i<(num_blocks-1);++i)
    {
        result+=futures[i].get();
    }
    result += last_result;
    return result;
}
