#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define N 1000000	// 1 million
#define N 30	// 1 million
float x[N];

// macro
#define max1(a, b) ( (a) > (b) ? (a) : (b) )

float arrmax1(int n) {
	if(n==1)
		return x[0];
	else
		return max1(x[n-1], arrmax1(n-1));
}

// function
float max2(float a, float b) { return a > b ? a : b; }

float arrmax2(int n) {
	if(n==1)
		return x[0];
	else
		return max2(x[n-1], arrmax2(n-1));
}

// macro -> function
#define max(a, b) max2(a, b)

float arrmax3(int n) {
	if(n==1)
		return x[0];
	else
		return max(x[n-1], arrmax3(n-1));
}

void measure(int i) {
	int start = clock();
	float result;
	switch(i) {
		case 1: result = arrmax1(N); break;
		case 2: result = arrmax2(N); break;
		case 3: result = arrmax3(N); break;
		default: break;
	}
	int clicks = clock() - start;
	printf("arrmax%d = %f takes %d\n", i, result, clicks);
}

int main() {
 	for(int i=0; i<N; i++)
		x[i] = N-i;
	
	measure(1);
	measure(2);
	measure(3);
}

