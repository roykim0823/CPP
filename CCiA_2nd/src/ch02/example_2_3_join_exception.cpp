#include <iostream>
#include <thread>
#include <stdexcept>
#include <chrono>
#include "common_objs.h"

void foo() {
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "hello from method \n";
}

void raise_exception() {
	std::cout << "This is other operation \n";
	throw std::runtime_error("this is a runtime error");
}

void try_block_only() {
	std::thread thread1(foo);

	try {
		raise_exception();
		thread1.join();
	} catch (...) {
	}
	std::cout << "This is main thread \n";
}

void catch_include_join() {
	std::thread thread1(foo);

	try {
		raise_exception();
		thread1.join();
	} catch (...) {
		thread1.join();
	}
}

void raii_version() {
	std::thread thread1(foo);
	thread_guard tg(thread1);

	try {
		raise_exception();
	} catch (...) {
	}
}


int main() {
	// compile each function separately

	// try_block_only();  // terminate
	// catch_include_join();
	raii_version();

	return 0;
}