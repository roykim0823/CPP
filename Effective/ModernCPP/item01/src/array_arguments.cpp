#include <array>
#include <cstddef>

void myFunc1(int param[]) {}
void myFunc2(int* param) {}   // same function as above

/*
 * Key idea:
 *
 *   In many contexts, an array decays into a pointer to its first element.
 *
 *   Although functions can't declare parameters that are truly arrays, they can
 *   declare parameters that are "references" to arrays.
 *
 *   Because array parameter declarations are treated as if they were pointer
 *   parameters, the type of an array that's passed to a template function by
 *   value is deduced to be a pointer type.
 *
 *   The type deduced for T is the actual type of the array!  That type includes
 *   the size of the array, so in this example T is deduced to be const
 *   char[13], and the type of f's parameter (a reference to this array) is
 *   const char (&)[13].
 *
 */

template<typename T>
void f_val(T param) {}  // template with by-value parameter

template<typename T>
void f_ref(T& param) {}  // template with by-reference parameter

int main()
{
    const char name[] = "J. P. Briggs";  	// name's type is
                                         	// const char[13]
                                         	
	const char * ptrToName = name;       	// array decays to pointer

    f_val(name);                   // what types are deduced for T and param?
                               		// -> name is array, but T deduced as const char*

	f_ref(name);                   				// pass array to f
}

/*
 * Key idea:
 *
 *   The ability to declare references to arrays enables creation of a template
 *   to deduce the number of elements that an array contains.
 */

// return size of an array as a compile-time constant. (The
// array parameter has no name, because we care only about
// the number of elements it contains.)
template<typename T, std::size_t N>                 // see info
constexpr std::size_t arraySize(T (&)[N]) noexcept  // below on
{                                                   // constexpr 
    return N;                                       // and
}                                                   // noexcept


int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };  // keyVals has
                                             // 7 elements

int mappedVals1[arraySize(keyVals)];         // so does
                                             // mappedVals

std::array<int, arraySize(keyVals)> mappedVals2;  // mappedVals'
                                                  // size is 7
