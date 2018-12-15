#include<iostream>
using namespace std;

// Caught Derived Exception
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
catch(Derived d) {
		cout<<"Caught Derived Exception";
}
catch(Base b) {
		cout<<"Caught Base Exception";
}
getchar();
return 0;
}
