#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <thread>
#include <chrono>
#include <condition_variable>

bool have_i_arrived = false;
int distance_my_destination = 10;
int distance_coverd = 0;
int final_stop=15;
std::condition_variable cv;
std::mutex m;

void keep_driving() {
	while (distance_coverd < final_stop) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		++distance_coverd;

		//notify the waiting threads if the event occurss
		if (distance_coverd == distance_my_destination)
			cv.notify_one();
	}
	std::cout << "Bus arrived the final stop, distance_coverd = " << distance_coverd << std::endl;;
}

// option 1
void keep_awake_all_night() {
	while (distance_coverd < distance_my_destination) {
		std::cout << "keep check, whether i am there \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << "Keep check, finally i am there, distance_coverd = " << distance_coverd << std::endl;;
}

// option2
void set_the_alarm_and_take_a_nap() {
	while (distance_coverd < distance_my_destination) {
		std::cout << "let me take a nap \n";
		std::this_thread::sleep_for(std::chrono::milliseconds(9000));
	}
	std::cout << "Alarm rings, finally i am there, distance_coverd = " << distance_coverd << std::endl;;
}

// option3
void ask_driver_to_wake_u_up_at_right_time() {
	std::unique_lock<std::mutex> ul(m);
	cv.wait(ul, [] {return distance_coverd == distance_my_destination;});  // it goes sleep if the condition is not true.
	std::cout << "CV, finally i am there, distance_coverd = " << distance_coverd << std::endl;;
}

int main() {
	std::thread driver_thread(keep_driving);

	std::thread passener1(keep_awake_all_night);
	std::thread passener2(set_the_alarm_and_take_a_nap);
	std::thread passener3(ask_driver_to_wake_u_up_at_right_time);

	driver_thread.join();
	passener1.join();
	passener2.join();
	passener3.join();
}