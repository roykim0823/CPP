#include <iostream>
#include "name_crtp.h"

using namespace std;

int main() {
	Name ned("Eddard", "Stark");
	cout << "ned.print()" << endl;
	ned.print();
	cout << "ned.repeat(10)" << endl;
	ned.repeat(10);
	
	return 0;
}
