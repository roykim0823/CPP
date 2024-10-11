#include <chrono>
#include <iostream>
#include <thread>

void test()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "hello from test \n";
}

void run() {
	std::thread thread1(test);
}

int main() {
	// run();  // error due to without join()

	std::thread thread1(test);

	if (thread1.joinable()) {
		std::cout << "before calling join(), this is joinable thread \n";
	} else {
		std::cout << "before calling join(), thread1 is not a joinable thread \n";
	}

	thread1.join();

	if (thread1.joinable()) {
		std::cout << "after calling join(), this is joinable thread \n";
	} else {
		std::cout << "after calling join(), thread1 is not a joinable thread \n";
	}

	std::cout << "hello from main thread \n";

	std::thread thread2;

	if (thread2.joinable()) {
		std::cout << "thread2 is joinable thread \n";
	} else {
		std::cout << "thread2 is not a joinable thread \n";
	}

}