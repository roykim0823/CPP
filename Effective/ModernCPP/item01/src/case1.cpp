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
 *   then, in the simplest case when ParamType is a reference type or a pointer
 *   type, but not a universal reference, type deduction works like this:
 *
 *   1. If expr's type is a reference, ignore the reference part.
 *   2. Then pattern-match expr's type against ParamType to determine T.
 
 *   3. If the type of f's parameter is changed from T& to const T&, the constness
 *   of cx and rx continues to be respected, but because we're now assuming that
 *   param is a reference-to-const, there's no longer a need for const to be
 *   deduced as part of T.
 *
 *   4. If param were a pointer (or a pointer to const) instead of a reference,
 *   things would work essentially the same way as 1 and 2:
 */

template<typename T>
void f(T& param) {}   		// param is a reference

template<typename T>
void fc(const T& param) {}  // param is now a ref-to-const

template<typename T>
void fptr(T* param) {}      // param is now a pointer

int main()
{
  int x = 27;         // x is an int
  const int cx = x;   // cx is a const int
  const int& rx = x;  // rx is a reference to x as a const int

  f(x);               	// T is int, 		param's type is int&
  f(cx);              	// T is const int,	param's type is const int&
  f(rx);              	// T is const int,	param's type is const int&
  
  fc(x);                // T is int, 		param's type is const int&
  fc(cx);               // T is int, 		param's type is const int&
  fc(rx);               // T is int, 		param's type is const int&
  
  const int *px = &x;   // px is a ptr to x as a const int

  fptr(&x);       	    // T is int, 		param's type is int*
  fptr(px);             // T is const int,	param's type is const int*
}
