#include <iostream>
#include "name_mixin.h"

using namespace std;

int main() {
	Name ned("Eddard", "Stark");
	cout << "ned.print()" << endl;
	ned.print();

	// Using mixin class
	cout << "RepeatPrint<Name>(ned).repeat(10)" << endl;
	RepeatPrint<Name>(ned).repeat(10);

	// Using template function without template arguments
	cout << "repeatPrint(ned).repeat(10)" << endl;
	repeatPrint(ned).repeat(10);

	return 0;
}
