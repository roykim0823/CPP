/* C++ Inheritance
   	1. Every data member defined in the base class 
	2. Every ordinary member function of parent class
	- although such members (data or funtion) may not always be accessible in the derived class!
	3. the same initial data layout as the base class
	
	Not inherited: base class's constructor, destructor and friends
*/

/* RTTI (Run-Time Type Information) in C++
	RTTI is a mechanism that exposes information about an object's data type at run time
	and is available only for the classes which have at least one virtual function.
*/

// RTTI (Run-Time Type Information)

#include<iostream> 
using namespace std; 

class B { }; 
class D: public B {}; 

// Adding a virtual function to the base class B makes it working.
class Bv { virtual void fun() {} }; 
class Dv: public Bv { }; 
  
int main() 
{ 
	/*
    B *b = new D; 
    D *d = dynamic_cast<D*>(b);		// compilation error since class D has no virtual function
    if(d != NULL) 
        cout<<"D works"; 
    else
        cout<<"D cannot cast B* to D*"; 
    */

	Bv *bv = new Dv; 
    Dv *dv = dynamic_cast<Dv*>(bv); 
    if(dv != NULL) 
        cout<<"Dv works" << endl; 
    else
        cout<<"Dv cannot cast Bv* to Dv*" << endl; 
    
	return 0; 
} 

