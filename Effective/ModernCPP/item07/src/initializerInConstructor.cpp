#include <iostream>

/*
 *	In constructor calls, parentheses and braces have the same meaning as
 *  long as std::initializer_list parameters are not involved.
 */
class Widget1 {
public:
  // ctors not declaring std::initializer_list params
  Widget1(int i, bool b) { std::cout << "Widget1(int, bool)" << std::endl; };      
  Widget1(int i, double d) { std::cout << "Widget1(int, double)" << std::endl; };  
};

void Widget1_ctor() {
  // In constructor calls, parentheses and braces have the same meaning as
  // long as std::initializer_list parameters are not involved:
  Widget1 w1(10, true);  // calls first ctor
  Widget1 w2{10, true};  // also calls first ctor
  Widget1 w3(10, 5.0);   // calls second ctor
  Widget1 w4{10, 5.0};   // also calls second ctor
}

/* 
 *  If one or more constructors declare a parameter of type std::initializer_list,
 *  calls using the braced initialization syntax strongly prefer the overloads
 *  taking std::initializer_lists.  Strongly.  If there's any way for compilers
 *  to construe a call using braced initializer to be to a constructor taking a
 *  std::initializer_list, compilers will employ that interpretation.
 *
 *  Even what would normally be copy and move construction can be hijacked by
 *  std::initializer_list constructors.
 */
class Widget2 {
public:
  Widget2(int i, bool b) { std::cout << "Widget2(int, bool)" << std::endl; };      
  Widget2(int i, double d) { std::cout << "Widget2(int, double)" << std::endl; };  
  
  Widget2(std::initializer_list<long double> il) {  // added
    std::cout << "Widget2(std::initializer_list<long double>)" << std::endl;
  };

  operator float() const {  // convert to float
    std::cout << "operator float() const" << std::endl;
  }
};

void Widget2_ctor() {
  Widget2 w1(10, true);  // uses parens and, as before, calls first ctor
  Widget2 w2{10, true};  // uses braces, but now calls std::init_list ctor
                         // (10 and true convert to long double)

  Widget2 w3(10, 5.0);   // uses parens and, as before, calls second ctor
  Widget2 w4{10, 5.0};   // uses braces, but now calls std::initializer_list ctor
                         // (10 and 5.0 convert to long double)

  Widget2 w5(w4);        // uses parens, calls copy ctor
  Widget2 w6{w4};        // uses braces, calls std::initializer_list ctor
                         // (w4 converts to float, and float converts to long double)

  Widget2 w7(std::move(w4));  // uses parens, calls move ctor
  Widget2 w8{std::move(w4)};  // uses braces, calls std::initializer_list ctor
                              // (for same reason as w6)
}

/*
 *	Compiler's determiniation to match braced initializers with constructors
 *  taking std::initializer_lists is so strong, it prevails even if the
 *  best-match std::initializer_list constructor can't be called.
 */
class Widget3 {
public:
  Widget3(int i, bool b) { std::cout << "Widget3(int, bool)" << std::endl; };      
  Widget3(int i, double d) { std::cout << "Widget3(int, double)" << std::endl; };  

  Widget3(std::initializer_list<bool> il) {  // element type is
                                            // now bool
    std::cout << "Widget3(std::initializer_list<bool>)" << std::endl;
  };

  // ...      	// no implicit conversion funcs
};

void Widget3_ctor() {
  //Widget3 w{10, 5.0};   // error! requires narrowing conversions
}

/*
 *	Only if there's no way to convert the types of the arguments in a braced
 *  initializer to the type in a std::initializer_list do compilers fall back
 *  on normal overload resolution.
 */

class Widget4 {
public:
  Widget4(int i, bool b) { std::cout << "Widget4(int, bool)" << std::endl; };      
  Widget4(int i, double d) { std::cout << "Widget4(int, double)" << std::endl; };  

  // std::init_list element type is now std::string
  Widget4(std::initializer_list<std::string> il) {  // added
    std::cout << "Widget(std::initializer_list<std::string>)" << std::endl;
  };

  // ...    // no implicit conversion funcs
};

void Widget4_ctor() {
  Widget4 w1(10, true);  // uses parens, still calls first ctor
  Widget4 w2{10, true};  // uses braces, now calls first ctor
  Widget4 w3(10, 5.0);   // uses parens, still calls second ctor
}

/*
 *  Empty braces mean no arguments, not an empty std::initializer_list.
 *
 *  If you want to call a std::initializer_list constructor with an
 *  empty std::initializer_list, you do it by making the empty braces
 *  a constructor argument - by putting the empty braces inside the
 *  parentheses or braces demarcating what you're passing.
 *
 *  For more discussion, see also blog post [1].
 *
 */
class Widget5 {
public:

  Widget5() {  // default ctor
    std::cout << "Widget5()" << std::endl;
  };

  Widget5(std::initializer_list<int> il) {  // std::init_list ctor
    std::cout << "Widget5(std::initializer_list<int>)" << std::endl;
  };

  // ...                                   // no implicit
                                           // conversion funcs
};

void Widget5_ctor() {
  Widget5 w1;    	// calls default ctor
  Widget5 w2{};  	// also calls default ctor
  Widget5 w3();  	// most vexing parse! declares a function!
  Widget5 w4({});  	// calls std::init_list ctor with empty list
  Widget5 w5{{}};  	// ditto
}

int main()
{
  	Widget1_ctor();  
  	Widget2_ctor();  
  	Widget3_ctor();  
  	Widget4_ctor();  
  	Widget5_ctor();  
}
