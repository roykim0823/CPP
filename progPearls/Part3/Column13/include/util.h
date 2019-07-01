/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

#ifndef INTSET_UTIL_H_
#define INTSET_UTIL_H_
#include <iostream>
#include <set>

using namespace std;

int bigrand()
{
	return RAND_MAX*rand() + rand();
}

int randint(int l, int u)
{
	//return l + bigrand() % (u-l+1);	// original  	
	return l + bigrand() % (unsigned)(u-l+1);	// return positive numbers
}


// p.134 func -> template func: test each set
template <typename T>
void gensets(int n, int maxval)
{
	T S(n, maxval);
	while (S.size() < n) {
		//S.insert(bigrand() % maxval);
		S.insert(randint(0, maxval));
	}
	
	int *v = new int[n];
	S.report(v);
	int j=1;
	for (int i = 0; i < n; i++, j++) {
		cout << v[i] << "\t";
		if(j%10==0)
			cout << endl;
	}
	if((j-1)%10!=0)
		cout << endl;
}

template <typename T>
void memaccesstest(int m, int n) {
	T S(m, n);
	// change among Arr, List and List2
	for (int i = 0; i < m; i++)
		S.insert(i);
}

void overheadonly(int m, int n) {
	int i, *v = new int[m];
	for (i = 0; i < m; i++)
		v[i] = bigrand() % n;
		for (i = 0; i < m; i++)
			cout << v[i] << "\n";
}

#endif // INT_SET_UTIL_H_
