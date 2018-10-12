/*
 * Key idea:
 *
 *   Considering the general form for templates and calls to it:
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *     f(expr);                // deduce T and ParamType from expr
 *
 *   then, in the simplest case when ParamType is a pointer type or a reference
 *   type, but not a universal reference, type deduction works like this:
 *
 *   1. If expr's type is a reference, ignore the reference part.
 *   2. Then pattern-match expr's type against ParamType to determine T.
 *
 *   If the type of f's parameter is changed from T& to const T&, the constness
 *   of cx and rx continues to be respected, but because we're now assuming that
 *   param is a reference-to-const, there's no longer a need for const to be
 *   deduced as part of T.
 */

template<typename T>
void f_ref(T& param) {}   				// param is a reference

template<typename T>
void f_ref2const(const T& param) {}  	// param is a ref-to-const

template<typename T>
void f_ptr(T* param) {}      			// param is a pointer

int main()
{
  int x = 27;         		
  const int cx = x;        	
  const int& rx = x;       	
  const int *px = &x;    	// px is a ptr to x as a const int

  f_ref(x);               	// T is int, 	   	param's type is int&
  f_ref(cx);              	// T is const int,	param's type is const int&
  f_ref(rx);              	// T is const int,	param's type is const int&
  
  f_ref2const(x);         	// T is int, 	   	param's type is const int&
  f_ref2const(cx);        	// T is int, 	   	param's type is const int&
  f_ref2const(rx);        	// T is int, 	   	param's type is const int&
  
  f_ptr(&x);              	// T is int, 		param's type is int*
  f_ptr(px);              	// T is const int,	param's type is const int*
}
