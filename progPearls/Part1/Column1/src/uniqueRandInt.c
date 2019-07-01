// gen $1 distinct integers from U[0,$2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAXN 10000000

int x[MAXN];

int randint(int a, int b)
{
	return a + (unsigned)(RAND_MAX * rand() + rand()) % (b + 1 - a);
}

void swap(int *i, int *j) {
	int t;
	t = *i;
	*i = *j;
	*j = t;
}

void swap_idx(int i, int j) {
	int t;
	t = x[i];
	x[i] = x[j];
	x[j] = t;
}


int main(int argc, char *argv[])
{
	int i, k, n, p;
	srand((unsigned) time(NULL));
	if(argc < 3) {
		printf("Usage: ./uniqueRandInt k n [k distinct integers from U[0, n)\n");
		return 0;
	}
	k = atoi(argv[1]);
	n = atoi(argv[2]);

	// Sorted array
	for(i=0; i<n; i++) 
		x[i] = i;
	
	// Shuffle
	for(i=0; i<k; i++) {
		p = randint(i, n-1);
		swap(&x[i], &x[p]);
		//swap_idx(i, p);
		printf("%d\n", x[i]);
	}
	return 0;
}
