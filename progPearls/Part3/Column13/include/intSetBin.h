/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */
#ifndef INT_SET_BIN_H_
#define INT_SET_BIN_H_
#include "util.h"	
#include "intSetList.h"	// to get struct node and list, use IntSetList

// p.141: combination of list and bit vectors
class IntSetBin {
private:
	int n, bins, maxval;
	IntSetList **bin;
	int binShift; 	// problem 9
public:
	IntSetBin(int maxelements, int pmaxval)
	{
		bins = maxelements;
		maxval = pmaxval;
		
		bin = new IntSetList*[bins];
		for(int i=0; i<bins; i++) {
			bin[i] = new IntSetList(0, maxval);
		}
        n=0;


	}
	int size() { return n; }
	
	void insert(int t)
	{
		int i = t / (1 + maxval/bins); // CHECK !
		//bin[i] = rinsert(bin[i], t);
		bin[i]->insert(t);
		n++;
	}

	void report(int *v)
	{
		for (int i = 0; i < bins; i++) {
			bin[i]->report(v);
			v = v+bin[i]->size();
		}
	}
};

#endif	// INT_SET_BIT_H_ 
