#include <iostream>
#include <thread>
#include <chrono>

void sum(int x, int y) {
	std::cout << " X + Y = " << x + y << std::endl;
}

void run_sum() {
	int p = 9;
	int q = 8;

	std::thread thread1(sum, p, q);
	thread1.join();
}


void pass_ref(int& x) {
	int i=0;
	while (i<10) {
		std::cout << "Thread1 x value : " << x << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		++i;
	}
}

void run_pass_x() {
	int x = 9;
	std::cout << "Main thread current value of X is : " << x << std::endl;
	// std::thread thread1(pass_ref, x);  // compilation error
	std::thread thread1(pass_ref, std::ref(x));
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	x = 15;
	std::cout << "Main thread X value changed to : " << x << std::endl;
	thread1.join();
}


int main() {
	run_sum();
	run_pass_x();
}