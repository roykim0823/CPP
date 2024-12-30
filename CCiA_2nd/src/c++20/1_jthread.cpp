#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void do_some_work() {
    std::cout << "Do some work." << std::endl;
}

void do_something_with_token(std::stop_token token) {
   int counter{ 0 };
   while (counter < 10) {
       if (token.stop_requested()) {
            std::cerr << "This thread is interrupted." << std::endl;
           return;
       }
       std::this_thread::sleep_for(200ms);
       std::cerr << "This is interruptible thread : " << counter << std::endl;
       ++counter;
   }
}

void do_something_without_token() {
   int counter{ 0 };
   while (counter < 10) {
       std::this_thread::sleep_for(200ms);
       std::cerr << "This is non-interruptible thread : " << counter << std::endl;
       ++counter;
   }
}

int main() {
    std::thread thread1(do_some_work);
    thread1.join();

    std::jthread interruptible(do_something_with_token);  // no need to call join();
    std::jthread non_interruptible(do_something_without_token);  // no need to call join();

    std::this_thread::sleep_for(1.0s);
    interruptible.request_stop();
    non_interruptible.request_stop();

    return 0;
}