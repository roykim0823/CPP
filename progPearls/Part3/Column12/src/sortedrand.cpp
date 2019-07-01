/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sortedrand.cpp -- output m sorted random ints in U[0,n) */

#include <iostream>
#include <set>
#include <algorithm>
#include <time.h>

using namespace std;

//-------------------------------------
// 12.5.1
//-------------------------------------
int bigrand()
{
	return RAND_MAX*rand() + rand();
}

int randint(int l, int u)
{  
//	return l + bigrand() % (u-l+1);
//	return l + bigrand() % (unsigned)(u-l+1);	// works
	return l + (unsigned)bigrand() % (u-l+1);  	// works
}
//-------------------------------------

void genknuth(int m, int n)	// p.127
{
	for(int i = 0; i < n; i++) {
		/* select m of remaining n-i */
		if ((bigrand() % (n-i)) < m) {
			cout << i << " ";
			m--;
			// added to fix bug
			if(m <= 0)
				break;
		}
	}
	cout << endl;
}

void gensets(int m, int n)	// p.128
{
	//set<int> S;
	//set<int>::iterator i;
	set<unsigned> S;
	set<unsigned>::iterator i;
	while (S.size() < (unsigned)m) {
		int t = bigrand() % (unsigned)n;
		S.insert(t);
	}
	for (i = S.begin(); i != S.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

void genshuf(int m, int n)	// p.129
{
	int i, j;
	int *x = new int[n];
	// init the array x
	for (i = 0; i < n; i++) 
		x[i] = i;
	
	for (i = 0; i < m; i++) {
	   	j = randint(i, n-1);
	   	int t = x[i]; x[i] = x[j]; x[j] = t;
	}

	sort(x, x+m);
	for (i = 0; i < m; i++)
	  	cout << x[i] << " ";
	
	cout << endl;
}

//-------------------------------------
// 12.5.9
//-------------------------------------
void genfloyd(int m, int n)
{
	set<int> S;
	set<int>::iterator i;
	for (int j = n-m; j < n; j++) {
		int t = bigrand() % (unsigned)(j+1);
		if (S.find(t) == S.end())
			S.insert(t); // t not in S
			else
				S.insert(j); // t in S
	}
	for (i = S.begin(); i != S.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

//-------------------------------------
// 12.5.7
//-------------------------------------
// print the random integers in decreasing order 
void randselect(int m, int n) {
	if (m > 0) {
		if (rand() % n < m) {
			printf("%d ", n-1);	
			randselect(m-1, n-1);
		}
		else
			randselect(m, n-1);
	}
}

// Sol: print the random integers in increasing order 
/*
Printing the random integers in increasing order is a matter of playing with the recursion: we just need to place the print after making a recursive call. Thus, this piece of code:

if (bigrand() % n) < m
	print n-1
	randselect(m-1, n-1)

Turns into:

if (bigrand() % n) < m
	randselect(m-1, n-1)
	print n-1

The algorithm is still the same, we just print the numbers later in time, after the recursion winds back. Because the logical and semantic ways the algorithm works were not changed, the resulting program is still correct.
*/
void randselectInc(int m, int n) {
	if (m > 0) {
		if (rand() % n < m) {
			randselectInc(m-1, n-1);
			printf("%d ", n-1);
		}
		else
			randselectInc(m, n-1);
	}
}

int main(int argc, char *argv[])
{
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	printf("genknuth(%d, %d):\t", m, n); 	genknuth(m, n);
	printf("gensets(%d, %d):\t", m, n); 	gensets(m, n);
	printf("genshuf(%d, %d):\t", m, n); 	genshuf(m, n);
	printf("genfloyd(%d, %d):\t", m, n); 	genfloyd(m, n);
	printf("randselect(%d, %d):\t", m, n); 	randselect(m, n); 			cout << endl;
	printf("randselectInc(%d, %d):\t", m, n); 	randselectInc(m, n);   	cout << endl;
	return 0;
}
