4. When n is a positive integer at most the size of the array, this recursive C function returns the maximum value in the array x[0..n-1]:

	float arrmax(int n)
	{
		if (n == 1)
			return x[0];
		else
			return max(x[n-1], arrmax(n-1));
	}
	
When max is a function, it finds the maximum element of a vector with n = 10,000 elements in a few milliseconds. When max is the C macro
	
	#define max(a,b) ((a) > (b) ? (a) : (b))
	
this algorithm takes 6 seconds to find the maximum of n=27 elements and 12 seconds to find the maximum of n=28 elements. Give an input that tickles this dreadful behavior, and analyze the run time mathematically.
-------------------------------------------------------------------------------
The problem with the macro is that the function is called more than once when arrmax(n-1) is greater than x[n-1]. With max() as a macro, the code inside the else section expands into:

	return ((x[n-1]) > (arrmax(n-1)) ? (x[n-1]) : (arrmax(n-1)))
	
As you can see, every case for which x[n-1] is less than or equal to arrmax(n-1), the call arrmax(n-1) is repeated, and the recursion goes all the way down again just to calculate the same thing again. And remember that
every call will do this, so the algorithm is be extremely slow if we use a macro for max().

The worst case scenario is an array sorted in reverse order, like this:

{ 100, 99, 98, 97, 96, 95, 94, ..., 1 }

Because x[n-1] is always less than or equal to arrmax(n-1), so the "else" part of the conditional expression is evaluated, and arrmax(n-1) is called again.

We can define the time that a problem of size n takes to be solved with the macro verion, T(n), using the following recurrence:

T(n) = 2T(n-1) + c
T(1) = c

This means that the time taken to solve a problem of size n is the time taken to solve a problem of size n-1 twice (because in the worst case, max() calls arrmax() twice) plus some constant value c (we assume that c
is the cost of doing constant time operations, such as checking if n == 1, etc.)

Expanding this recurrence a little bit helps us deriving a general expression:
(Note: the notation sum(j,k,expr) means "the sum of expr with i going from j up to k (including j and k))

T(n) = 2T(n-1) + c =
= 2(2T(n-2)+c)+c =
= 2(2(2T(n-3)+c)+c)+c =
= 2(2(2(2T(n-4)+c)+c)+c)+c =
= ... = 2^(n-1)T(1) + sum(0,n-2,c*2^i) =
= 2^(n-1)T(1) + c(2^(n-1) - 1)

The dominating term is the exponentiation on 2^(n-1), so the algorithm is O(2^n). This is very inefficient.

What if max() is a regular function? Well, the arguments are evaluated before calling it, so there's only 1 recursive call inside arrmax(). The recurrence would be given by:

T(n) = T(n-1) + c

Again, expanding it is a good way to derive a general expression:

T(n) = T(n-1) + c = T(n-2) + c + c = T(n-3) + c + c + c = T(n-4) + c + c + c + c = ... = T(1) + c*(n-1)

The dominating term is c*n, making it O(n). So, basically, if max() is a macro, the code will run in O(2^n) time, if it's a function, it will run in O(n) time. Impressive!


6. C and C++ libraries provide character classification functions such as isdigit, isupper and islower to determine the types of characters. How would you implement those functions?
-------------------------------------------------------------------------------
These functions are typically implemented as macros, to avoid function call overhead, and their definition is inside the system file ctype.h

You can look at an article where I write about it in my blog at http://codinghighway.com/?p=307

Assume that we call ctype's functions with an argument x. An efficient implementation that is common is to use an array that is indexed by x, where each position holds an integer, and each bit in that integer describes
a property of x. Because we use x to index an array, ctype.h macros require that x is an integer that represents an unsigned char, or EOF (EOF is guaranteed to be a negative constant so that it is not mixed up with
an existing character). There are various masks to test for isolated interesting bits. For example, array[x]&DIGIT will test if x is a digit. The implementation is system dependent.

7. Given a very long sequence (say, billions or trillions) of bytes, how would you efficiently count the total number of one bits? (That is, how many bits are turned on in the entire sequence?)
-------------------------------------------------------------------------------
K&R gives a good example of how to count bits without iterating through every bit in an integer. In exercise 2.9 (chapter 2), it is said that:
	In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x
You can read the reasoning behind this in my solutions to K&R exercises at https://codinghighway.kilnhg.com/Code/Repositories/Group/KR/Files (go to chapter 2, exercise 2-9, and give a look at the readme file)

This C code uses this method to count the number of 1 bits in an unsigned integer:

int bitcount(unsigned x) {
        int i;
        for (i = 0; x; i++, x &= (x-1));
        return i;
}

To apply this to billions or trillions of bits, we have to break them into a known size - perhaps the size of an integer (normally 32 bits) - and use this function.
