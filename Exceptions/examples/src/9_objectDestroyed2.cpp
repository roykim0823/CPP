#include <iostream>
using namespace std;

class Test1 {
public:
Test1() { cout << "Constructing an Object of Test1" << endl; }
~Test1() { cout << "Destructing an Object of Test1" << endl; }
};

class Test2 {
public:
// Following constructor throws an integer exception
Test2() { cout << "Constructing an Object of Test2" << endl;
			throw 20; }
~Test2() { cout << "Destructing an Object of Test2" << endl; }
};

/* Destructors are only called for the completely constructed objects.
   When constructor of an object throws an exception, destructor for that
	 object is not called.
*/
int main() {
try {
	Test1 t1; // Constructed and destructed
	Test2 t2; // Partially constructed
	Test1 t3; // t3 is not constructed as this statement never gets executed
} catch(int i) {
	cout << "Caught " << i << endl;
}
}
