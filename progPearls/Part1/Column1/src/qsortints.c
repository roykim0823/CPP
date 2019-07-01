// 	qsortints.c -- Sort input set of integers using qsort
// 	Sort distinct integers in the range [0..N-1]

#include <stdio.h>
#include <stdlib.h>
#define N 10000000

int intcomp(int *x, int *y) { return *x - *y; }


int a[N];

int main() {
	int i, n=0;

	while(scanf("%d", &a[n]) != EOF)
		n++;

	qsort(a, n, sizeof(int), intcomp);

	for(i=0; i<n; i++)  {
		printf("%d\n", a[i]);
	}
	
	return 0;
}
