// Detecting Memory Access Error
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	const int size=1000;
	int n, sum=0;
	int *A = (int*) malloc(sizeof(int)*size);

	for(n=size-1; n>=0; n--)	
		A[n]=n;                 
	for(n=0; n<size; n++)       
		sum+=A[n];              
	printf("sum = %d\n", sum);
	free(A);
	return 0;
}
