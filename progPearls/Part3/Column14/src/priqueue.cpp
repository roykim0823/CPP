/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* priqueue.cpp -- priority queues (using heaps) */

#include <iostream>
#include "priqueue.h"

using namespace std;

int bigRand() { return RAND_MAX*rand() + rand(); }
int randint(int l, int u) {
	return l+ bigRand() % (unsigned)(u-l+1);	// return positive
}

void print(int *vec, int n) {
	int j=1;
	for(int i=0; i<n; i++, j++) {
		cout << vec[i] << "\t";
		if(j%10==0)
			cout << endl;
	}
	if((j-1)%10 != 0)
		cout << endl;
}
	
	
int main()
{
	const int n = 10;
	int	v[n], sorted[n];

	for(int i=0; i<n; i++) {
		v[i] = randint(0, 1000);
	}
	pqsort(v, n);
	print(v, n);

	priqueue<int>pq(n);
	for(int i=0; i<n; i++) {
		pq.insert(randint(0, 1000));
	}
	for(int i=0; i<n; i++) {
		sorted[i] = pq.extractmin();
	}
	print(sorted, n);
	
	for(int i=0; i<n; i++) {
		v[i] = randint(0, 1000);
	}
	print(v, n);
	heapSort(v, n-1);	// since the heapsort start at index 1
	print(v, n);

	return 0;
}
