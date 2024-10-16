#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

#include "simple_thread_pool.h"

int main() {
	thread_pool pool;
	std::cout << "Testing thread pool" << std::endl;

	for (int i = 0; i < 32; i++)
	{
		pool.submit([=] {
			printf(" %d printed by thread - %d \n", i, std::this_thread::get_id());
		});
	}

	return 0;
}