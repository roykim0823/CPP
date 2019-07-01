/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */

#ifndef INT_SET_BITVECTOR_H_
#define INT_SET_BITVECTOR_H_
#include "util.h"

// p.140 
class IntSetBitVec {
private:
	enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
	int n, hi, *x;
	
	void set(int i) { x[i>>SHIFT] |= (1<<(i & MASK)); }
	void clr(int i) { x[i>>SHIFT] &= ~(1<<(i & MASK)); }
	int test(int i) { return x[i>>SHIFT] & (1<<(i & MASK)); }
			
public:
	IntSetBitVec(int maxelements, int maxval)
	{
		hi = maxval;
		x = new int[1 + hi/BITSPERWORD];
		for (int i = 0; i < hi; i++)
			clr(i);
		n = 0;
	}
	int size() { return n; }
	void insert(int t)
	{
		if (test(t))
			return;
		set(t);
		n++;
	}
	void report(int *v)
	{
		int j=0;
		for (int i = 0; i < hi; i++)
			if (test(i))
				v[j++] = i;
	}
	~IntSetBitVec() { delete [] x; }
};

#endif
