/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* priqueue.cpp -- priority queues (using heaps) */

#include <iostream>

using namespace std;

// define and implement priority queues
template<class T>
class priqueue {
public:
   	priqueue(int m)
   	{
   		maxsize = m;
   		x = new T[maxsize+1];
   		n = 0;
   	}
	~priqueue() { delete [] x; }

	void insert(T t)
   	{
   		int i, p;
   		x[++n] = t;
		
		// shift up
		// pre	n>0 && heap(1, n-1)
		// post	heap(1, n)
   		for (i = n; i > 1 && x[p=i/2] > x[i]; i = p)
   			swap(p, i);
   	}

	T extractmin()
   	{
   		int i, c;
   		T t = x[1];	// t is the min

   		x[1] = x[n--];
		// shift down
		// pre 	heap(2, n) && n>=0
		// post heap(1, n)
   		for (i = 1; (c=2*i) <= n; i = c) {
   			if (c+1<=n) { 		// c is the left child of i
				if(x[c+1]<x[c])	// c+1 is the right child of i
   					c++;
			}
  			if (x[i] <= x[c]) 	// c is the lesser child of i
   				break;
   			swap(c, i);
   		}
   		return t;
   	}

private:
	int	n, maxsize;
	T *x;
	
	void swap(int i, int j)	{ T t = x[i]; x[i] = x[j]; x[j] = t; }
};

// sort with priority queues (heap sort is strictly better)
template<class T>
void pqsort(T v[], int n)
{
	priqueue<T> pq(n);	// use n+1 additional memory used for the heap
	int i;
	for (i = 0; i < n; i++)
		pq.insert(v[i]);
	for (i = 0; i < n; i++)
		v[i] = pq.extractmin();
}

// shiftUp and shiftDown for heapSort (MaxHeap)
template<typename T>
void swap(T x[], int i, int j)	
{ 	T t = x[i]; x[i] = x[j]; x[j] = t; }

template<typename T>
void shiftUp(T x[], int n) {
	int p;
	for(int i = n; i > 1 && x[p=i/2] < x[i]; i=p)
		swap(x, p, i);
}

template<typename T>
void shiftDown(T x[], int n) {
	int c;
	for(int i = 1; (c=2*i) <= n; i=c)  {
		if(c+1<=n && x[c+1]>x[c])
			c++;
		if(x[i]>=x[c])
			break;
		swap(x, c, i);
	}
}

template<typename T>
void heapSort(T v[], int n) 
{
	for(int i=2; i<=n; i++) {
		// invariant: heap(1, i-1)
		shiftUp(v, i);
		// heap(1, i)
	}
	for(int i=n; i>=2; i--) {
		// heap(1, i)  	&& sorted(i+1, n) && x[1..i] 	<= x[i+1...n]
		swap(v, 1, i);
		// heap(2, i-1) && sorted(i, n) && x[1..i-1] 	<= x[i...n]
		shiftDown(v, i-1);
		// heap(1, i-1) && sorted(i, n) && x[1..i-1] 	<= x[i...n]
	}
}
