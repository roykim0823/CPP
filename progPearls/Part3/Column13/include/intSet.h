/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */

#ifndef INTSET_H_
#define INTSET_H_
#include <iostream>
#include <set>
#include "util.h"

using namespace std;

// p.133: class IntSetImp -> template base class IntSet 
template <typename T>
class IntSet {      
protected:
	T S;
public:
	//IntSet(int n, int maxval) { }
	virtual void insert(int t) = 0;
	virtual int size() = 0;
	virtual void report(int *v) = 0;
};

// p.134 class IntSetSTL
class IntSetSTL: public IntSet<set<int>> {
public:
	IntSetSTL(size_t n, int maxval) {} 
	int size() 			{ return S.size(); }
	void insert(int t) 	{ S.insert(t);}
	void report(int *v)
	{
		int j=0;
		set<int>::iterator i;
		for (i = S.begin(); i != S.end(); ++i) 
			v[j++] = *i;
	}
};

// p.135 IntSetArray
class IntSetArr: public IntSet<int*> {
private:
	size_t n;
public:
	IntSetArr(int maxSize, int maxval) {
		S = new int[maxSize+1];	// +1 is for sentinel: maxval at S[n]
		n = 0;
		S[n] = maxval;
	}
	int size() { return n; }
	void insert(int t) {
		int i, j;
		for(i=0; S[i] < t; i++)	// skip elements less than t 
			;
		if(S[i] == t)			// found t then just return
			return ;
		for(j=n; j>=i; j--)		// shift right all elements larger than t
			S[j+1] = S[j];
		S[i] = t;
		n++;
	}
	void report(int *v) {
		for(size_t i=0; i<n; i++) 
			v[i] = S[i];
	}
	~IntSetArr() { delete [] S; }
};

#endif // INT_SET_H_
