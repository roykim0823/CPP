#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
#include <functional>

#include "include/simple_thread_pool.h"

int main() {
	SimpleThreadPool<std::function<void()>> pool;
	std::cout << "Testing thread pool" << std::endl;

	for (int i = 0; i <100; ++i) {
		pool.submit([=] {
			printf("%d printed by thread - %u\n", i, std::this_thread::get_id());
		});
	}

	return 0;
}