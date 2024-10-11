#include <iostream>
#include <thread>
#include <chrono>

void func_2(int& x) {
	while (true) {
		std::cout << x << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void func_1() {
	int x = 5;
	std::thread thread_2(func_2, std::ref(x));
	// Be careful when using detach with ref argument!
	thread_2.detach();  // x will cause an exception whtn the func_1 finishes!
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "thread_1 finished execution \n";
}


int main() {
	std::thread thread_1(func_1);
	thread_1.join();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	// thread_1 finishes, but the detached thread_2 keeps running -> Seg Fault!
}