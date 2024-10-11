#include <chrono>
#include <iostream>
#include <thread>

void foo()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "hello from foo\n";

}

void bar()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "hello from bar\n";

}

int main() {
	std::thread foo_thread(foo);
	std::thread bar_thread(bar);
	bar_thread.detach();
	std::cout << "This is after bar thread detach\n";

	foo_thread.join();
	std::cout << "This is after foo thread join\n";

	return 0;
}