#include <list>
#include <algorithm>
#include <iostream>
#include <vector>

#include "include/parallel_sorter.h"

int main()
{
	std::cout << "Simple thread pool with waiting for other tasks \n";
	const int size = 800;
	std::list<int> my_array;

	srand(0);

	for (size_t i = 0; i < size; i++)
	{
		my_array.push_back(rand());
	}

	my_array = parallel_quick_sort<int, ThreadPoolWaitLocalQueue<function_wrapper>>(my_array);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << my_array.front() << std::endl;
		my_array.pop_front();
	}
}