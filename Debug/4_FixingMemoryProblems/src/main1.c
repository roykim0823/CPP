// Detecting Memory Access Error
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	const int size=1000;
	int n, sum=0;
	int *A = (int*) malloc(sizeof(int)*size);

	for(n=size; n>0; n--)		// A[100]...A[1], Invalid write of size 4 at A[100]
	//for(n=size-1; n>=0; n--)	// Corrected
		A[n]=n;                 // Error: A[100] invalid write
	for(n=0; n<size; n++)       // A[0]...A[99]
		sum+=A[n];              // Error: A[0] is not initialized
	printf("sum = %d\n", sum);
	return 0;                   // No free(): mem leak: A[]
}
