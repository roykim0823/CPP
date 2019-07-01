/* Copyright (C) 1999 Lucent Technologies
 From 'Programming Pearls' by Jon Bentley
 sort.cpp -- test and time
Input lines: algnum
Output lines: algnum
This is predominantly a C
sort function immediately
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// To change from C++ back to C, remove the following two lines
// and the call to sort in main
//#include <algorithm>
//using namespace std;
// Data and supporting functions

#define MAXN 10000000
typedef int DType;
DType data[MAXN];
DType realx[MAXN];

int *x = realx; // allow x to shift for heaps
int n;

void swap(int i, int j)
{
	DType t = x[i];
	x[i] = x[j];
	x[j] = t;
}

int randint(int l, int u)
{
	return l + (RAND_MAX*rand() + rand()) % (u-l+1);
}

// LIBRARY QSORT
int intcomp(int *x, int *y)
{
	return *x - *y;
}

// INSERTION SORTS
// Simplest insertion sort
void insertSort1()
{
	int i, j;
	for (i = 1; i < n; i++)
		for (j = i; j > 0 && x[j-1] > x[j]; j--)
			swap(j-1, j);
}

// Write swap function inline
void insertSort2()
{
	int i, j;
	DType t;
	for (i = 1; i < n; i++)
		for (j = i; j > 0 && x[j-1] > x[j]; j--) {
			t = x[j];
			x[j] = x[j-1];
			x[j-1] = t;
		}
}

// Move assignments to and from t out of loop
void insertSort3()
{
	int i, j;
	DType t;
	for (i = 1; i < n; i++) {
		t = x[i];
		for (j = i; j > 0 && x[j-1] > t; j--) {
			x[j] = x[j-1];
		}
		x[j] = t;
	}
}

// QUICKSORTS
// Simplest version, Lomuto partitioning
void qsort1(int l, int u)
{
	int i, m;
	if (l >= u)
		return;

	m = l;  	// pivot t=x[l], l=first index
	for (i = l+1; i <= u; i++) {
		// invariant: x[l+1..m] 	<  x[l] &&
		//			  x[m+1..i-1] 	>= x[l]
		if (x[i] < x[l])
			swap(++m, i);
	}

	swap(l, m);	// move the pivot to x[m], it is removed in qsort2
	qsort1(l, m-1);
	qsort1(m+1, u);
}

// Sedgewick's version of Lomuto, with sentinel
void qsort2(int l, int u)
{
	int i, m;
	if (l >= u)
		return;

	m = i = u+1;
	do {
   		do i--;
		while (x[i] < x[l]);
   		swap(--m, i);
   	} while (i > l);

	qsort2(l, m-1);
	qsort2(m+1, u);
}

// Two-way partitioning
void qsort3(int l, int u)
{
	int i, j;
	DType t;
	if (l >= u)
		return;

	t = x[l];
	i = l;
	j = u+1;
	for (;;) {
		do i++; while (i <= u && x[i] < t);
		do j--; while (x[j] > t);
		if (i > j)
			break;
		swap(i, j);
	}

	swap(l, j);
	qsort3(l, j-1);
	qsort3(j+1, u);
}

// qsort3 + randomization + insertSort small subarrays + swap inline
int cutoff = 50;
void qsort4(int l, int u)
{
	int i, j;
	DType t, temp;
	if (u - l < cutoff)
		return;

	swap(l, randint(l, u));
	t = x[l];
	i = l;
	j = u+1;

	for (;;) {
		do i++; while (i <= u && x[i] < t);
		do j--; while (x[j] > t);
		if (i > j)
			break;
		temp = x[i]; x[i] = x[j]; x[j] = temp;
	}

	swap(l, j);
	qsort4(l, j-1);
	qsort4(j+1, u);
}

// selection: k-th smallest element
void select1(int l, int u, int k)
{
	int i, j;
	DType t, temp;
	if (l >= u)
		return;

	swap(l, randint(l, u));
	t = x[l];
	i = l;
	j = u+1;

	for (;;) {
		do i++; while (i <= u && x[i] < t);
		do j--; while (x[j] > t);
		if (i > j)
			break;
		temp = x[i]; x[i] = x[j]; x[j] = temp;
	}
	swap(l, j);

	if (j < k)
		select1(j+1, u, k);
	else if (j > k)
		select1(l, j-1, k);
}

// HEAP SORTS
void siftup(int u)
{
	int i, p;
	i = u;
	for (;;) {
		if (i == 1)
			break;
		p = i / 2;
		if (x[p] >= x[i])
			break;
		swap(p, i);
		i = p;
	}
}

void siftdown1(int l, int u)
{
	int i, c;
	i = l;
	for (;;) {
		c = 2*i;
		if (c > u)
			break;
		if (c+1 <= u && x[c+1] > x[c])
			c++;
		if (x[i] > x[c])
			break;
		swap(i, c);
		i = c;
	}
}

void siftdown1b(int l, int u) // More C-ish version of 1
{
	int i, c;
	for (i = l; (c = 2*i) <= u; i = c) {
		if (c+1 <= u && x[c+1] > x[c])
			c++;
		if (x[i] > x[c])
			break;
		swap(i, c);
	}
}

void hsort1()
{
	int i;
	x--;
	for (i = 2; i <= n; i++)
		siftup(i);
	for (i = n; i >= 2; i--) {
		swap(1, i);
		siftdown1(1, i-1);
	}
	x++;
}

void hsort2()
{
	int i;
	x--;
	for (i = n/2; i >= 1; i--)
		siftdown1(i, n);
	for (i = n; i >= 2; i--) {
		swap(1, i);
		siftdown1(1, i-1);
	}
	x++;
}

// push to bottom, then back up
void siftdown3(int l, int u) {
	int i, c, p;
	i = l;
	for (;;) {
		c = 2*i;
		if (c > u)
			break;
		if (c+1 <= u && x[c+1] > x[c])
			c++;
		swap(i, c);
		i = c;
	}
	for (;;) {
		p = i/2;
		if (p < l)
			break;
		if (x[p] > x[i])
			break;
		swap(p, i);
		i = p;
	}
}

void hsort3()
{
	int i;
	x--;
	for (i = n/2; i >= 1; i--)
		siftdown3(i, n);
	for (i = n; i >= 2; i--) {
		swap(1, i);
		siftdown3(1, i-1);
	}
	x++;
}
void siftdown4(int l, int u) // replace swap with assignments
{
	int i, c, p;
	DType t;
	t = x[l];
	i = l;
	for (;;) {
		c = 2*i;
		if (c > u)
			break;
		if (c+1 <= u && x[c+1] > x[c])
			c++;
		x[i] = x[c];
		i = c;
	}
	x[i] = t;
	for (;;) {
		p = i/2;
		if (p < l)
			break;
		if (x[p] > x[i])
			break;
		swap(p, i);
		i = p;
	}
}

void hsort4(){
	int i;
	x--;
	for (i = n/2; i >= 1; i--)
		siftdown4(i, n);
	for (i = n; i >= 2; i--) {
		swap(1, i);
		siftdown4(1, i-1);
	}
	x++;
}
// Other Sorts -- Exercises in Column 11
void selsort() // Selection sort
{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = i; j < n; j++)
			if (x[j] < x[i])
				swap(i, j);
}

void shellsort()
{
	int i, j, h;
	for (h = 1; h < n; h = 3*h + 1)
		;

	for (;;) {
		h /= 3;
		if (h < 1) break;
		for (i = h; i < n; i++) {
			for (j = i; j >= h; j -= h) {
				if (x[j-h] < x[j]) break;
					swap(j-h, j);
			}
		}
	}
}

// SCAFFOLDING
// Timing
void timedriver(int size)
{
	int i, k, algnum, mod, start, clicks;

	n = size;
	algnum=14;
	mod=n*2;

	// Init data
	for(int i=0; i<n; i++)
		data[i] = randint(0, mod-1);

	for(int alg=0; alg<algnum; alg++) {
		// copy data to x
		memcpy(x, data, sizeof(int)*n + 1);
		start = clock();

		switch (alg) {
			//case 11: qsort(x, n, sizeof(int), (int (__cdecl *)(const void *,const void
			//*)) intcomp); break;
			//case 11: qsort(x, n, sizeof(int), intcomp); break;
			//case 12: sort(x, x+n); break;	// for C++ algorithm
			case 0: printf("insertSort1()\t"); 	insertSort1(); break;
			case 1: printf("insertSort2()\t"); 	insertSort2(); break;
			case 2: printf("insertSort3()\t"); 	insertSort3(); break;
			case 3: printf("quickSort1()\t");	qsort1(0, n-1); break;
			case 4: printf("quickSort2()\t");	qsort2(0, n-1); break;
			case 5: printf("quickSort3()\t");	qsort3(0, n-1); break;
			case 6: printf("quickSort4()\t");	qsort4(0, n-1);  insertSort3(); break;
			case 7: printf("select1()\t");		k=n/2; select1(0, n-1, k); break;
			case 8: printf("hsort1()\t");		hsort1(); break;
			case 9: printf("hsort2()\t");		hsort2(); break;
			case 10: printf("hsort3()\t");		hsort3(); break;
			case 11: printf("hsort4()\t");		hsort4(); break;
			case 12: printf("selsort()\t");		selsort(); break;
			case 13: printf("shellsort()\t");		shellsort(); break;
			default: break;
		}
		clicks = clock() - start;
		if (alg == 7) { // Test selection
			for (i = 0; i < k; i++)
				if (x[i] > x[k])
					printf(" SELECT BUG1 i=%d k=%d x[i]=%d, x[k]=%d\n", i, k, x[i], x[k]);
			for (i = k+1; i < n; i++)
			  	if (x[i] < x[k])
			   		printf(" SELECT BUG2 i=%d\n", i);
		} else { // Test sort
			for (i = 0; i < n-1; i++)
				if (x[i] > x[i+1])
					printf(" SORT BUG i=%d\n", i);
		}
		printf("%d\t%d\t%g\n", n, clicks, 1e9*clicks/((float) CLOCKS_PER_SEC*n));
	}
}

// Main
int main(int argc, char *argv[])
{
	if(argc<2) return 0;

	int size = atoi(argv[1]);
	timedriver(size);
	return 0;
}
