#include<iostream>
using namespace std;

/* If both base and derived classes are caught as exceptions then catch block
   of derived class must appear before the base class.
   If we put base class first then the derived class catch block will never
   be reached. For example, following C++ code prints “Caught Base Exception”
*/

class Base {};
class Derived: public Base {};

int main()
{
Derived d;
// some other stuff
try {
	// Some monitored code
	throw d;
}
catch(Base b) {
		cout<<"Caught Base Exception";
}
catch(Derived d) { //This catch block is NEVER executed
		cout<<"Caught Derived Exception";
}
getchar();
return 0;
}
