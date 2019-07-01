#include <stdio.h>
#include <stdlib.h>

double calculate_a_n(double *c, double *t, int k, int n);

int main(int argc, char *argv[]) {
	int i, k, m;
	double *terms;
	double *consts;
	
	sscanf(argv[1], "%d", &k); 	// a degree of the order
	
	terms = (double *) malloc(sizeof(double)*k);
	consts = (double *) malloc(sizeof(double)*(k+1));
	
	/* Input:
	   k, a_1, ..., a_k, c_1, ..., c_(k+1), m
	 */
	
	/* Capture terms a_1 .. a_k */
	for (i = 0; i < k; i++)
		sscanf(argv[i+2], "%lf", terms+i);
	/* Capture constants c_1 .. c_(k+1) */
	for (i = 0; i < k+1; i++)
		sscanf(argv[i+k+2], "%lf", consts+i);
	
	sscanf(argv[2*k+3], "%d", &m);
	
	for (i = 0; i < m; i++)
		printf("a_%d = %.4f\n", i+1, calculate_a_n(consts, terms, k, i+1));
		
	return 0;
}

// Note that this is not, by far, the most efficient approach, but it's the easiest, 
// and it's the one that goes with the definition. 
// A more intelligent program would use memoization to avoid a massive number of recursive calls 
// to calculate values that were already calculated in the past.
double calculate_a_n(double *c, double *t, int k, int n) {
	double res;
	int i;
	if (n <= k) {
		return t[n-1];
	}
	res = 0.0;
	for (i = 0; i < k; i++)
		res += c[i]*calculate_a_n(c, t, k, n-i-1);
	res += c[k];
	return res;
}
