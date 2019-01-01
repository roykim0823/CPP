#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

void print(std::vector<std::string> &&t) {
	for(auto str : t) {
		std::cout << str << std::endl;
	}
	std::cout << std::endl;
}

// 1.1: iterator interface
std::vector<std::string> split1_1(std::string text) {
	std::istringstream iss(text);
	
	// the extra parantheses in the first parameter are made to disambiguate from a function call
	// -> "most vexing parse" in the item 6 of Effective STL
	std::vector<std::string> tokens( (std::istream_iterator<std::string>(iss)),
									  std::istream_iterator<std::string>());
	return tokens;
}

// 1.1-B: iterator interface , C++11
std::vector<std::string> split1_1_B(std::string text) {

	std::istringstream iss(text);
	// C++11 with uniform initialization
	std::vector<std::string> tokens( std::istream_iterator<std::string>{iss}, 
									  std::istream_iterator<std::string>());
	return tokens;
}

/* 1.2: Pimp my operator >> 
 * inheriting from std::string though std::string doesn't have a virtual destructor.
 * so, it should not inherit from it.
 * However, inheritance does not cause a problem in itself. Unless
 * 	- a pointer to inherited is deleted in the form of a pointer to std::string
 *  - with slicing problem
*/
template <char delimiter>
class WordDelimitedBy : public std::string {};

// overload operator >>
template <char delimiter>
std::istream& operator>>(std::istream& is, WordDelimitedBy<delimiter>& output) {
	std::getline(is, output, delimiter);
	return is;
}

std::vector<std::string> split1_2(std::string text) {

	std::istringstream iss(text);
	// C++11 with uniform initialization
	std::vector<std::string> tokens( std::istream_iterator<WordDelimitedBy<';'>>{iss}, 
									 std::istream_iterator<WordDelimitedBy<';'>>());
	return tokens;
}

// 1.3 Tokenizing ***
std::vector<std::string> split(std::string s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	
	while(std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

int main() {
	std::string text  = "Let me split this into words";
	std::string text2 = "Let;me;split;this;into;words";

	// 1. Iteration on a stream
	std::cout << "1. Iteration on a stream" << std::endl;
	print(split1_1(text));
	print(split1_1_B(text));
	print(split1_2(text2));
	print(split(text, ' '));
	print(split(text2, ';'));

	// 2. using Boost
	std::cout << "2. Using Boost" << std::endl;
	std::vector<std::string> results;
	boost::split(results, text, [](char c) { return c==' '; });
	print(std::move(results));

	/* 3. Using range (C++20)
	std::cout << "2. Using range" << std::endl;
	auto splitText = text | view::split(' ');
	print(std::move(splitText));
    */

	return 0;
}
	
