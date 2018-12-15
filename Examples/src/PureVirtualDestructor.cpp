/* Can a destructor be pure virtual in C++?
	- Yes
*/

#include <iostream> 
class Base 
{ 
public: 
    virtual ~Base()=0; // Pure virtual destructor, make the base abstrct class 
};

// A class that contains pure virtual destructor "must"
// provide a function doby for the pure virtual destructor.
// without it, compilation error

// With the function body of pure virtual destructor, Base class is still abstact class
// So, instantiation of Base class causes compilation error 
Base::~Base() 
{ 
    std::cout << "Pure virtual destructor is called"<< std::endl; 
} 

class Derived : public Base 
{ 
public: 
    ~Derived() 
    { 
        std::cout << "~Derived() is executed" << std::endl; 
    } 
}; 
  
int main() 
{ 
    Base *b = new Derived(); 
    delete b; 
    return 0; 
}

