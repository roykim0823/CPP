#include "crtp1_addingFunctionality.h"
#include <iostream>

using namespace std;

int main() {
	Sensitivity s;
	s.setValue(1.1);
	cout << s.getValue() << endl;
	s.square();
	cout << s.getValue() << endl;
	return 0;
}
