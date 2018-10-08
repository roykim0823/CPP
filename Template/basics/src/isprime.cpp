#include <utility>
#include <string>
#include <iostream>
#include "isprime.hpp"

int main()
{
	auto isPrime9 = IsPrime<9>::value;
	std::cout << isPrime9 << std::endl;
	std::cout << IsPrime<11>::value << std::endl;
	std::cout << IsPrime<13>::value << std::endl;
	std::cout << IsPrime<15>::value << std::endl;

	return 0;
}
