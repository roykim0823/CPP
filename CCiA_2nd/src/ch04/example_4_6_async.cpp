#include <iostream>
#include <future>
#include <string>
#ifndef __APPLE__
#include <syncstream>
#endif
#include <thread>

void printing() {
#ifndef __APPLE__
	std::osyncstream(std::cout) << "printing runs on tid: " << std::this_thread::get_id() << std::endl;
#else
	std::cout << "printing runs on tid: " << std::this_thread::get_id() << std::endl;
#endif
}

int addition(int x, int y) {
#ifndef __APPLE__
	std::osyncstream(std::cout) << "addition runs on tid: " << std::this_thread::get_id() << std::endl;
#else
	std::cout << "addition runs on tid: " << std::this_thread::get_id() << std::endl;
#endif
	return x + y;
}

int substract(int x, int y) {
#ifndef __APPLE__
	std::osyncstream(std::cout) << "substract runs on tid: " << std::this_thread::get_id() << std::endl;
#else
	std::cout << "substract runs on tid: " << std::this_thread::get_id() << std::endl;
#endif
	return x - y;
}

int main() {
#ifndef __APPLE__
	std::osyncstream(std::cout) << "main thread id: " << std::this_thread::get_id() << std::endl;
#else
	std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;
#endif

	int x = 100;
	int y = 50;

	std::future<void> f1 = std::async(std::launch::async, printing);
	std::future<int> f2 = std::async(std::launch::deferred, addition, x, y);
	std::future<int> f3 = std::async(std::launch::deferred | std::launch::async,  // compiler choose
		substract, x, y);

	f1.get();
	std::cout << "value recieved using f2 future: " << f2.get() << std::endl;
	std::cout << "value recieved using f3 future: " << f3.get() << std::endl;
}