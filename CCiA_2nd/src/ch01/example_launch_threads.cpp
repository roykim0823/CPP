#include <iostream>
#include <thread>

void func() {
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "Hello from function: " << std::this_thread::get_id() << std::endl;
}

class my_class {
public:
	void operator()() {
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		std::cout << "Hello from the class with function call operator: " << std::this_thread::get_id() << std::endl;
	}
};

int main() {
	//create thread using fuction
	std::thread thread1(func);

	//create thread using class with function call operator, callable object
	my_class mc;
	std::thread thread2(mc);

	//create thread using lambda expression
	std::thread thread3([] {
		std::cout << "Hello from the lambda: " << std::this_thread::get_id() << std::endl;
		});

	thread1.join();
	thread2.join();
	thread3.join();

	std::cout << "This is main thread: " << std::this_thread::get_id() << std::endl;

	return 0;
}