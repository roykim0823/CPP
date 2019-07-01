## Column 4: Writing Correct Programs
2. If the original binary search was too easy for you, try the variant that returns in p the position of the first occurrence of t in the array x (if there are multiple occurrences of t, the original algorithm returns anarbitrary one). Your code should make a logarithmic number of comparisons of array elements; it is possible to do the job in log(n) such comparisons.
--
The secret, as described in Section 9.3, is to use the invariant x[l] < t <= x[u]. The invariant is initialized by setting l = -1 and u = n, thus, we must assume that x[-1] < t and x[n] >= t. 
In order to find the first element that is equal to t, we want l and u such that l+1 = u, 
because this means that the first occurrence of t is in position u due to the invariant definition. 
Thus, the loop condition is while (l+1 != u).
This version of the binary search algorithm not only solves a harder problem, but it solves it faster, 
because only one comparison with x[m] is performed in each iteration. 
For more informations about this, refer to Section 9.3.

3. Write and verify a recursive binary search program. Which parts of the code and proof stay the same as in the iterative version, and which parts change?
--
Every recursive call holds the invariant that if t is in the array, then it must be between l and u. The invariant is initialized by the top root caller, binsrch(), which calls this with l = 0 and u = n-1. The following 
assertions are similar to the ones showed in the iterative version; in fact, the code is almost the same.
It can be seen that the recursion stops when l > u, and this condition is always met, because each recursive call shrinks the size of the range by at least one.

4. Add fictitious "timing variables" to your binary search program to count the number of comparisons it makes, and use program verification techniques to prove that its run time is indeed logarithmic.
--
The runtime is logarithmic because each recursive call computes the middle value of a given range, m = (l+u)/2, and it calls itself with that value either as a new upper or lower range bound. In a range with n elements,
how many times can we split it into two halves? Well, we can split it i times, where i is the number that makes the integer division n/2^i equal to 0. Solving for this, we have:

log(n/2^i) = 1 <=> log(n) - i = 1 <=> i = log(n) - 1

And, thus, we have O(log(n)) comparisons, because for each value of m we make O(1) comparisons.

This can be checked empirically by using a variable that is incremented for each comparison made. My solution does so with the help of a global variable called comps.

6. [C. Scholten] David Gries calls this the "Coffee Can Problem" in his Science of Programming. You are initially given a coffee can that contains some black beans and some white beans and a large pile of "extra" black beans. You then repeat the following process until there is a single bean left in the can. Randomly select two beans from the can. If they are the same color, throw them both out and insert an extra black bean. If they are different colors, return the white bean to the can and throw out the black.
Prove that the process terminates. What can you say about the color of the final remaining bean as a function of the numbers of black and white beans originally in the can?
--
The process can be broken down in pseudo-code like this:
	x = number of beans in the can (black + white)
	while there are beans in the can
		pick 2 beans x and y
		if x.color == y.color
			throw x and y away
			x -= 2
			insert extra black bean
			x++
		else
			Let z be the black bean
			throw z away
			x--

Notice that both of the 2 possible branches decrement x, the total number of beans in the can, by 1. Thus, a loop invariant is that the total number of beans in the can is equal to x. Because x is decremented by 1 in each iteration, the process always terminates. 
Another loop invariant is that either we threw away 2 white beans, or we threw away 0 white beans; this means that white beans parity is always preserved. Thus, if there's an odd number of white beans, we will eventuallyget to a point where only 1 white bean remains in the can, and it's impossible to remove it because if we pick this white bean and another black one, the rule says to throw the black one away and keep the white. So we will always keep it to the end. If there's an even number of white beans, the last bean is black: eventually, we will pick 2 white beans and throw them both away. This will happen for every pair of white beans, until we pick the last 2 white beans and replace it with one of the extra black beans.

7. A colleague faced the following problem in a program to draw lines on a bit-mapped display. An array of n pairs of reals 
```
(a_i, b_i) defined the n lines y_i = a_(i)*x + b_i. 
```
The lines were ordered in the x-interval [0, 1] in the sense that y\_i < y\_(i+1) for all values of i between 0 and n-2 and all values of x in [0, 1].

Less formally, the lines don't touch in the vertical slab. Given a point (x,y), 
where 0 <= x <= 1, 
he wanted to determine the two lines that bracket the point. How could he solve the problem quickly?
--
The key to find something in an ordered set quickly is almost always binary search. In this particular example, however, we don't want to find an element, we want to find a pair of elements that brackets a point.

The principle is the same, but instead of stopping the search when we hit the element we were looking for, we will stop the search when our range consists of 2 adjacent neighbors in the ordered array. The general idea
is that in the beginning we know that if x is between any two lines in the array, then it must be between a pair of lines in the range array[0]..array[n-1]. We then make a traditional binary search, and we stop as soon as the lower bound is greater than or equal to the upper bound minus 1. There's a subtle point to keep in mind here, which is to protect the method against values that are not bracketed between any two lines in the array.
For this, the lower limit is initialized to -1, and the upper limit is initialized to n; if we perform a binary search and one of the range limits remains -1 or n in the end, then the value is off bounds.
Notice that it also might be the case that the point (x,y) lies exactly in one of the lines in the array. In this case, the result is not a pair of lines, but instead it is just one position.

This method is described by the following pseudo-code:

l1 = -1
l2 = n
while l1 < l2-1
	m = (l1+l2)/2
	if x is below line m
		l2 = m
	else if x is above line m
		l1 = m
	else
		l1 = l2 = m
if (l1 == -1 || l2 == n)
	l1 = l2 = -1;

l1 is the lower bound (as in "line1"), and l2 (as in "line2") is the upper. In the end, one of three cases can happen: l1 and l2 are -1, meaning that it is not possible to bracket x between 2 lines; l1 and l2 are different, meaning that x is between l1 and l2, or l1 and l2 are the same, meaning that x lies exactly in that line.

The algorithm is O(log(n)) because it uses a modified binary search version. It is nearly impossible to make it more efficient. 

In the real implementation, l1 and l2 are pointers passed by the caller, where the result will be stored.

8. Binary search is fundamentally faster than sequential search: to search an n-element table, it makes roughly log(n) comparisons while sequential search makes roughly n/2. While it is often fast enough, in a few cases binary search must be made faster yet. Although you can't reduce the logarithmic number of comparisons made by the algorithm, can you rewrite the binary search code to be faster? 
For definiteness, assume that you are to search a sorted table of n = 1000 integers.
--
This problem is described and analysed in Section 9.3. We exploit the fact that n = 1000 to build a hardcoded binary search where the range size is always a power of two.

Note that this is an extreme case where we don't care about code readability, simplicity and maintainability. You should never have code like this in real world programs. There is often a trade off to decide between
readability and efficiency; they usually are opposite goals, and it is your job to find an average point in the middle.

For more information on this exercise, please refer to Section 9.3.

NOTE: There's a small bug in the binary search code on Section 9.3. Every 3 versions of the binary search algorithm presented in pages 94 and 95 have this final if clause:
	if p > 1000 || x[p] != t
This should be:
	if p >= 1000 || x[p] != t
Since p = 1000 would yield an out-of-bounds array access (and, in fact, it doesn't even have to be >=, it could be ==). I tried reporting this error, and although I found the errata online, no contact information
was provided anywhere (I even search for the author's name on google and found several pages about him, but no e-mail!), so, sadly, I can't do anything about it.

9. As exercises in program verification, precisely specify the input/output behavior of each of the following program fragments and show that the code meets its specification. The first program implements the vector
addition a = b + c.
	i = 0
	while i < n
		a[i] = b[i] + c[i]
		i = i+1
(This code and the next two fragments expand the "for i = [0,n)" loop to a while loop with an increment at the end.) The next fragment computes the maximum value in the array x.
	max = x[0]
	i = 1
	while i < n do
		if x[i] > max
			max = x[i]
		i = i+1
This sequential search program returns the position of the first occurrence of t in the array x[0..n-1].
	i = 0
	while i < n && x[i] != t
		i = i+1
	if i >= n
		p = -1
	else
		p = i
This program computes the n-th power of x in time proportional to the logarithm of n. This recursive program is straightforward to code and to verify; the iterative version is subtle, and is left as an additional problem.
	function exp(x, n)
			pre n >= 0
			post result = x^n
		if n = 0
			return 1
		else if even(n)
			return square(exp(x, n/2))
		else
			return x*exp(x, n-1)
--
Program1:
	i = 0
	while i < n
		/* invariant: a[0..i-1] = b[0..i-1]+c[0..i-1] */
		a[i] = b[i] + c[i]
		/* assert: a[0..i] = b[0..i] + c[0..i] */
		i = i+1
		/* assert: a[0..i-1] = b[0..i-1] + c[0..i-1] */
The code meets the specification: the loop invariant is initialized by setting i to 0, meaning that a is not b+c in any position, and it is preserved in each iteration because of the commented assertions inserted in the code.
The loop terminates because each iteration increments i by one unit, thus, i will eventually reach n and stop. Due to the loop invariant, when i == n, we know that a[0..n-1] = b[0..n-1] + c[0..n-1], which is exactly what
the specification asks for.

Program2:
	max = x[0]
	i = 1
	while i < n do
		/* invariant: max = max(x, 0, i-1) */
		if x[i] > max
			max = x[i]
		/* assert: max = max(x, 0, i) */
		i = i+1
		/* assert: max = max(x, 0, i-1)
This program is very easy to verify. The virtual function max(x, y, z) represents the maximum of array x in the interval [y, z]. It can be seen that the loop invariant is preserved as the program runs, and the loop terminates
because i is incremented one unit per iteration, so it will eventually reach n and stop. When it does, we know that i == n, and the invariant tells us that max = max(x, 0, n-1), so the program is correct.

Program3:
	i = 0
	while i < n && x[i] != t
		i = i+1
	/* assert: i >= n || x[i] == t */
	if i >= n
		p = -1
	else
		/* assert: i < n && (i >=n || x[i] == t) => x[i] == t */
		p = i
In this program, the loop stops when either it reaches the end of the array x, or it finds t in the array x. So, after the loop breaks, we are guaranteed to know that i >= n || x[i] == t. The code then makes appropriate
tests to see which of these situations holds, and it meets the specification.

Program4:
	function exp(x, n)
			pre n >= 0
			post result = x^n
		if n = 0
			return 1
		else if even(n)
			/* assert: x^n = (x^(n/2))^2 */
			return square(exp(x, n/2))
		else
			/* assert: even(n-1) && x^n = x*x^(n-1) */
			return x*exp(x, n-1)
Nice piece of code! The base case of the recursion is when n = 0, and it it always reached because the original n is always greater than or equal to 0, and each recursive call reduces n by n/2 (or by 1, depending on n's parity).
Mathematically, we know that (x^n)^y = x^(n\*y), so x^n = (x^(n/2))^2, but we can only use this for values of n such that n%2 == 0, or, equivalently, when n is even (we want to avoid fractional exponents). 
It can be seen in the code above that it is guaranteed that the rule is only applied when n is even. If n is odd, then n-1 must be even, and that's what happens in the final test.
Thus, the program conforms to its specification.

11. Write and prove the correctness of a recursive binary search function in C or C++ with this declaration:
	int binarysearch(DataType x[], int n) 
	Use this function alone; do not call any other recursive functions
--
There's a problem with such declaration: it is missing the element to search for. x is the array, and n must be the size of the array, since there's no way to know in C the array size. So I added a third parameter, t, whichis the element to search for.
My recursive implementation uses n as the array length; if the array's middle position is less than t, then the function is recursively called with a shifted array, x+m+1 (where m is the middle position).
This is the equivalent of upsizing the lower range bound value (l). The new array, x', is shifted m+1 positions, so that x'[0] is the same as x[m+1]. This means that we must add m+1 to this recursive call return value in
order to get the true position from the original array. We also have to be careful with n's value. In this case, x' will have n-(m+1) = n-m-1 elements, because x[0..m] has m+1 elements. Another key point to keep in mind is that if the recursive call returns -1, then we must return -1 in the current call as well, instead of adding m+1 to -1. 
Passing a shifted array and a new value for n in the recursive call is the secret not to use an explicit u and l as we did before.
An easier case is when x[m] > t; because we don't need to shift the array to the right, in this case, we just have to recursively call binarysearch() with n = m and return the same value that the recursion gives us.
This is the equivalent to downsizing the value for u.
The two cases in which the recursion stops is when either we reach a value of n = 0, meaning that we got to the end of every possible range without finding t, or when x[m] == t.
