#include <iostream>
#include <thread>

void func_1() {
	std::cout << "This is a function 1\n";
}

void func_2() {
	std::cout << "This is a function 2\n";
}

int main() {
	// no copy constructor and copy assignment in std::thread

	std::thread thread_1(func_1);

	// try to assigne one thread to another
	// std::thread thread_2 = thread_1; // compilation error

	//move one thread form another
	std::thread thread_2 = std::move(thread_1);

	//implicit call to move constructor
	thread_1 = std::thread(func_2);

	std::thread thread_3 = std::move(thread_2);

	// this is wrong
	// thread_1 = std::move(thread_3);  // cause exception when it move to active thread

	thread_1.join();
	// thread_2.join();  // thread_2 is already moved -> exception
	thread_3.join();

}