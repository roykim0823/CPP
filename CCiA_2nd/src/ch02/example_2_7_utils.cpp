#include <iostream>
#include <thread>
#include <chrono>

void get_hw_concurrency() {
	std::cout << "Allowed max number of parallel threads : "
		<< std::thread::hardware_concurrency() << std::endl;
}

void foo() {
	std::cout << "new  thread id : " << std::this_thread::get_id() << "\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void get_id_test() {
	std::thread thread1(foo);
	std::thread thread2(foo);
	std::thread thread3(foo);
	std::thread thread4;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::cout << "thread1 id before joining : " << thread1.get_id() << std::endl;
	std::cout << "thread2 id before joining : " << thread2.get_id() << std::endl;
	std::cout << "thread3 id before joining : " << thread3.get_id() << std::endl;
	std::cout << "thread4 (default) id before joining : " << thread4.get_id() << std::endl;

	thread1.join();
	thread2.join();
	thread3.join();
	std::cout << "thread3 id after joining : " << thread3.get_id() << std::endl;
}

int main() {
	get_id_test();	 		// example 1
	get_hw_concurrency();	// example 2
}