#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000000

typedef int DataType;

DataType x[MAXN];
int n;

// Scaffolding
int i = -999999;
#define assert(v) { if( (v) == 0 ) printf("	   binarysearch bug %d %d %d \n", i, n, x[i]); }

int sorted() // p50
{ int i; for(i=0; i<n-1; i++) if(x[i] > x[i+1]) return 0;
	return 1;
}

// Raw translation, p46-1
int binarySearch1(DataType t)
{
	int l, u, m;
	l = 0;
	u = n-1;
	for(;;) {
		if( l > u ) return -1;
		m = (l + u) / 2;
		if (x[m] < t)
			l = m+1;
		else if (x[m] == t)
			return m;
		else // x[m] > t
			u = m-1;
	}
}

// More C-ish, p46-2
int binarySearch2(DataType t)
{
	int l, u, m;
	l = 0;
	u = n-1;
	while(l <= u) {
		m = (l + u) / 2;
		if (x[m] < t)
			l = m+1;
		else if (x[m] == t)
			return m;
		else // x[m] > t
			u = m-1;
	}
	return -1;
}

int badsearch(DataType t) // p47
{
	int l, u, m;
	l = 0;
	u = n-1;
	while(l <= u) {
		m = (l + u) / 2;
		// printf("    %d %d %d\n", l, m, u);
		if (x[m] < t)
			l = m;
		else if (x[m] > t)
			u = m;
		else	// x[m] == t 
			return m;
	}
	return -1;
}


// Scaffolding to probe one algorithm, p47
// function pointer is added to check all the search functions
void probe1(int (*func_ptr)(DataType)) 
{
	int i;
	DataType t;
	while(scanf("%d %d", &n, &t) != EOF) {
		for(i=0; i<n; i++) 
			x[i] = 10*i;
		printf(" %d\n", (*func_ptr)(t));
	}
}

// p50-51
void test(int maxn, int (*func_ptr)(DataType)) {	// use function pointer instead of macro
	int i;
	for(n=0; n<=maxn; n++) {
		//printf("n=%d\n", n);
		// distinct elements (plus one at top)
		for(i=0; i<=n; i++) 
			x[i] = 10*i;
		for(i=0; i<n; i++) {
			assert( (*func_ptr)(10*i) == i );
			assert( (*func_ptr)(10*i - 5) == -1);
		}
		assert( (*func_ptr)(10*n - 5) 	== -1);
		assert( (*func_ptr)(10*n) 		== -1);
	
		// equal elements
		for(i=0; i<n; i++) 
			x[i] = 10;
		if(n==0) { 
			assert( (*func_ptr)(10) == -1);
		}
		else {
			assert( 0<= (*func_ptr)(10) && (*func_ptr)(10) < n);
		}
		assert( (*func_ptr)(5) 	== -1);
		assert( (*func_ptr)(15)	== -1);
	}
}

// Exericse 5.8.7
void scramble(int n)
{
	int i, j;
	DataType t;
	for(i=n-1; i>0; i--) {
		j = (RAND_MAX*rand() + rand()) % (i+1);
		t = x[i];
		x[i] = x[j];
		x[j] = t;
	}
}

// sequential search
int seqSearch1(DataType t) {
	int i;
	for(i=0; i<n; i++) {
		if(x[i]==t)
			return i;
	}
	return -1;
}

// Faster seqSearch with Sentinel
int seqSearch2(DataType t) {
	int i;
	DataType hold = x[n];
	x[n]=t;
	for(i=0; ; i++) {
		if(x[i]==t)
			break;
	}
	x[n]=hold;
	
	if(i==n)
		return -1;
	else
		return i;
}

// Sentinel + loop unrolling
int seqSearch3(DataType t) {
	int i;
	DataType hold = x[n];
	x[n]=t;
	for(i=0; ; i+=8) {
		if(x[i]==t)		break;
		if(x[i+1] == t) {i += 1; break; }
		if(x[i+2] == t) {i += 2; break; }
		if(x[i+3] == t) {i += 3; break; }
		if(x[i+4] == t) {i += 4; break; }
		if(x[i+5] == t) {i += 5; break; }
		if(x[i+6] == t) {i += 6; break; }
		if(x[i+7] == t) {i += 7; break; }
	}
	x[n]=hold;
	
	if(i==n)
		return -1;
	else
		return i;
}



void timedriver()
{
	int i, algnum, numtests, test, start, clicks;
	int run_scramble=0;
	int (*func_ptr)(DataType);
	scanf("%d %d %d", &n, &numtests, &run_scramble);

	for(i=0; i<=n; i++)
		x[i] = i;
	if(run_scramble>0)
		scramble(n);
	
	for(algnum=0; algnum<5; algnum++) {
		switch(algnum) {
		case 0: func_ptr = &binarySearch1;	break;
		case 1: func_ptr = &binarySearch2;	break;
		case 2: func_ptr = &seqSearch1;	break;
		case 3: func_ptr = &seqSearch2;	break;
		case 4: func_ptr = &seqSearch3;	break;
		}

		start = clock();
		for(test=0; test<numtests; test++) {
			for(i=0; i<n; i++) {
				//assert((*func_ptr)(x[i]) == x[i]);
				if((*func_ptr)(x[i]) != x[i])
					printf("XX: %d %d\n", (*func_ptr)(x[i]), x[i]);
			}
		}
		clicks = clock() - start;
		printf("%d\t%d\t%d\t%d\t%g\n",
			algnum, n, numtests, clicks,
			1e9*clicks/((float) CLOCKS_PER_SEC*n*numtests));
	}
}

int main()
{
//	printf("probe1(binarySearch1)...\n");
//	probe1(binarySearch1);
//	printf("probe1(binarySearch2)...\n");
//  probe1(binarySearch2);
//	printf("probe1(badsearch)...\n");
//	probe1(badsearch);
	test(25, binarySearch1);
	test(25, binarySearch2);
//	test(25, badsearch);
	timedriver();
	return 0;
}

