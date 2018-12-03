#include <string>
#include <list>
using namespace std;

class PhoneNumber{};

class ABEntry {

public:
  	ABEntry(const string& name, const string& address, 
  		const list<PhoneNumber>& phones);

private:
   string theName;
   string theAddress;
   list<PhoneNumber> thePhones;
   int numTimesConsulted;
};

/*
ABEntry::ABEntry(const string& name, const string& address, 
  		const list<PhoneNumber>& phones)
{
	// these are all assignments, not initializations
	// *All default constructor are called, and wasted
	theName = name;
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = 0;
}
*/

// A better way to write ABEntry constructor
// an object is initialized before the body of constructor is entered.
// the initialization list must be used for const or references (they can't be assigned)
ABEntry::ABEntry(const string& name, const string& address, 
  		const list<PhoneNumber>& phones)
	: 	theName(name),   		// these are now all initializations
		theAddress(address),
		thePhones(phones),
		numTimesConsulted(0)
	{}

int main() {
	return 0;
}
