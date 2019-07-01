#include <stdio.h>

void swap(char *a, char *b) {
	char t;
	t = *a;
	*a = *b;
	*b = t;
}

void reverse(char *v, int i, int j) {
	for (; i < j; i++, j--) {
		swap(&v[i], &v[j]);
	}
}

// This is very easy to do if we think about the reversal algorithm. 
// cba is the same as ((a_r)(b_r)(c_r))_r
// so we begin by reversing a, b and c, and then we reverse the whole string.
// My implementation uses a rotate() function that receives the vector to be rotated, 
// the number of elements in the "a" block, the number of elements in the "c" block, and the number of total elements in v.
void rotate(char *v, int i, int j, int n) {
	reverse(v, 0, i-1); 	// (a_r)bc
	reverse(v, i, n-j-1);   // (a_r)(b_r)c
	reverse(v, n-j, n-1);   // (a_r)(b_r)(c_r)
	reverse(v, 0, n-1);     // ((a_r)(b_r)(c_r))_r = cba
}

int main() {
	/* Example usage */
	char str[] = "Hello, world. This is an example.";
	rotate(str, 4, 11, 33);
	/* Expected result:
	   an example.o, world. This is Hell
	*/
	printf("%s\n", str);
	return 0;
}
