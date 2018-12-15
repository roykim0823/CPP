/* 	No Virual Constructor in C++ since C++ being static typed (the purpose of RTTI is different) 
   	language, it is meaningless to the C++ compiler to create an object polymorphically.
   	The compiler must be aware of the class type to create the ojbect. In other words, what type
   	of object to be created is a compile time decition from C++ compiler perspective.
   	If we make constructor virtual, compiler flags an error. In fact except inline, no other
   	keyword is allowed in the declaration of constructor.

	In practice scenarios we would need to create a derived class object in a class hierarchy based
	on some input. Putting in other words, "object creation and object type are tightly coupled
	which forces modifications to extended. The ojbective of virtual constructor is to decouple
	object creation from it's type." -> Factory Method
*/

#include <iostream>
using namespace std;

// Library Starts
class Base {
public:
	Base() {}
	virtual ~Base() {}
	virtual void DisplayAction() = 0;	// An interface

	// The "Virtual Constructor" -> Factory Method
	static Base *Create(int id);
};

class Derived1 : public Base {
public:
	Derived1() 	{ cout << "Derived1 created" << endl; }
	~Derived1() { cout << "Derived1 destroyed" << endl; }
	void DisplayAction() { cout << "Action from Derived1" << endl; }
}; 
class Derived2 : public Base {
public:
	Derived2() 	{ cout << "Derived2 created" << endl; }
	~Derived2() { cout << "Derived2 destroyed" << endl; }
	void DisplayAction()  { cout << "Action from Derived2" << endl; }
};

class Derived3 : public Base {
public:
	Derived3() 	{ cout << "Derived3 created" << endl; }
	~Derived3() { cout << "Derived3 destroyed" << endl; }
	void DisplayAction()  { cout << "Action from Derived3" << endl; }
};
// Library Ends

// Version1
class User {
public:
	User() : pBase(0) {
		// What if Dervied2 is required? - Add an if-else ladder 
		pBase = new Derived1();
	}
	~User() {
		if(pBase) {
			delete pBase;
			pBase = 0;
		}
	}

	// Delegates to actual object
	void Action() { pBase -> DisplayAction(); }
private:
	Base *pBase;
};

// Version2
class User2 {
public:
	User2() : pBase(0) {
		int input; 	// ID to distinguish between Derived1 and Derived2
		cout << "Enter ID (1 or 2): ";
		cin >> input;
		while( (input !=1) && (input !=2) ) {
			cout << "Enter ID (1 or 2 only): ";
			cin >> input;
		}
		if(input == 1)
			pBase = new Derived1();
		else
			pBase = new Derived2();
	}
	~User2() {
		if(pBase) {
			delete pBase;
			pBase = 0;
		}
	}

	// Delegates to actual object
	void Action() { pBase -> DisplayAction(); }
private:
	Base *pBase;
};

// Final Version
Base *Base::Create(int id) {
	// Just Expand the if-else ladder used in User2 class.
	// User code need not be recompiled to create newly added class objects
	if(id == 1)	return new Derived1;
	if(id == 2)	return new Derived2;
	if(id == 3)	return new Derived3;
}

class User3 {
public:
	User3() : pBase(0) {
		int input; 	// ID to distinguish between Derived1 and Derived2
		cout << "Enter ID (1 2, or 3): ";
		cin >> input;
		while( (input !=1) && (input !=2) && (input !=3)) {
			cout << "Enter ID (1,2  or 3 only): ";
			cin >> input;
		}
		// Get object from the "Virtual Constructor" (Factory Method)
		pBase = Base::Create(input);
	}
	
	~User3() {
		if(pBase) {
			delete pBase;
			pBase = 0;
		}
	}

	// Delegates to actual object
	void Action() { pBase -> DisplayAction(); }
private:
	Base *pBase;
};

int main() {

	// If User's consumer needs Derived2 functionality, User needs to create "new Derived2()" 
	// and it forces recompilation -> bad way of design
	User *user = new User();
	user->Action();	// Need Derived1 functionlity only
	delete user;

	// User2 is not open for extension, an inflexible design. 
	// If Derived3 is added, the User2 must be modified. -> recompilation required
	User2 *user2 = new User2();
	user2->Action();	// Need either Derived1 or Derived2 functionality
	delete user2;


	User3 *user3 = new User3();
	user3->Action();	// Need either Derived1 or Derived2 functionality
	delete user3;


}

