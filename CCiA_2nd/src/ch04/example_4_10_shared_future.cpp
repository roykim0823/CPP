#include <iostream>
#include <thread>
#include <future>
#include <stdexcept>
#include <chrono>
#include <mutex>

/******************************* Example 1 ******************************/
void print_result1(std::future<int>& fut) {
	//std::cout << fut.get() << "\n";
	if (fut.valid()) {
		std::cout << "this is valid future\n";
		std::cout << fut.get() << "\n";
	} else {
		std::cout << "this is invalid future\n";
	}
}

void run_code1() {
	std::promise<int> prom;
	std::future<int> fut(prom.get_future());

	// single future is used in multiple thread -> segmentation fault!
	std::thread th1(print_result1, std::ref(fut));
	std::thread th2(print_result1, std::ref(fut));

	prom.set_value(5);

	th1.join();
	th2.join();
}

/************************************* Example 2 **************************************/

void print_result_shared(std::shared_future<int>& fut) {
	std::cout << fut.get() << "  - valid future \n";
}

void print_result_shared2(std::shared_future<int>& fut) {
	if (fut.valid()) {
		std::cout << "this is valid future: " << fut.get() << "\n";
	} else {
		std::cout << "this is invalid future\n";
	}
}

void run_code2() {
	std::promise<int> prom;
	std::shared_future<int> fut(prom.get_future());  // shared_future for multiple threads

	std::thread th1(print_result_shared, std::ref(fut));
	std::thread th2(print_result_shared2, std::ref(fut));
	std::thread th3(print_result_shared2, std::ref(fut));

	prom.set_value(5);

	th1.join();
	th2.join();
	th3.join();
}

int main()
{
	//run_code1();  // segmentation fault
	run_code2();

	return 0;
}
