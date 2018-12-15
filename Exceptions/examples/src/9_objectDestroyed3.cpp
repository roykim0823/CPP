#include <iostream>
using namespace std;

class Test {
static int count;
int id;
public:
Test() {
	count++;
	id = count;
	cout << "Constructing object number " << id << endl;
	if(id == 4)
	throw 4;
}
~Test() { cout << "Destructing object number " << id << endl; }
};

int Test::count = 0;

// a exception throw during the construction of 4th element.
// it calls previous three objects' destructor
int main() {
try {
	Test array[5];
} catch(int i) {
	cout << "Caught " << i << endl;
}
}
