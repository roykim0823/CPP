// CPP program to illustrate 
// difference b/w std::remove 
// and std::vector::erase algorithm 
#include <bits/stdc++.h> 

int main() 
{ 
	std::vector<int> vec { 10, 20, 30, 30, 20, 10, 10, 20 }; 
	std::vector<int> vec2{ 10, 20, 30, 30, 20, 10, 10, 20 }; 

	// Print original vector 
	std::cout << "Original vector :" << std::endl; 
	for (int i = 0; i < vec.size(); i++) 
		std::cout << " " << vec[i]; 
	std::cout << "\n"; 

	// std :: remove function call 
	auto pend = std::remove(vec.begin(), vec.end(), 20); 
	// Print the vector after std :: remove 
	std::cout << "Range contains after remove 20:" << std::endl;; 
	for (auto p = vec.begin(); p != pend; ++p) 
		std::cout << ' ' << *p; std::cout << '\n'; 

	// Print original vector 
	std::cout << "Original Vector after remove 20:" << std::endl;; 
	for (int i = 0; i < vec.size(); i++) 
		std::cout << " " << vec[i]; 
	std::cout << "\n"; 

	// std :: vector :: erase function call 
	// erase the first 3 elements of vector vector 
	vec2.erase(vec2.begin(), vec2.begin() + 3); 
	std::cout << "Vector vec2 after erase first 3 elements:" << std::endl;; 
	for (int i = 0; i < vec2.size(); i++) 
		std::cout << " " << vec2[i]; 
	std::cout << "\n"; 

	return 0; 
} 

