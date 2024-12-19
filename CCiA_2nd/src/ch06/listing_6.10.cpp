#include <iostream>
#include "include/listing_6.10_queue_fine_lock_final.h"

int main()
{
	threadsafe_queue<int> queueInteger;
	queueInteger.push(5645);
	queueInteger.push(87456);
	queueInteger.push(94564);
	queueInteger.push(2347);
	queueInteger.push(634);

	queueInteger.printData();

	std::cout << "Removing: " << *(queueInteger.try_pop().get()) << std::endl;
	std::cout << "Removing: " << *(queueInteger.try_pop().get()) << std::endl;
	std::cout << "Removing by wait_pop(): " << *(queueInteger.wait_and_pop().get()) << std::endl;
	queueInteger.printData();

	std::cout << "Removing by wait_pop(): " << *(queueInteger.wait_and_pop().get()) << std::endl;
	queueInteger.printData();

	std::cout << "Removing: " << *(queueInteger.try_pop().get()) << std::endl;
	queueInteger.printData();

	return 0;
}
