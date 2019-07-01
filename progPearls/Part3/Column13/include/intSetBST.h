/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */

#ifndef INTSET_BST_H_
#define INTSET_BST_H_
#include "util.h"
#include "intSet.h"

// p.138-139 IntSetBST
struct Bnode {
	int val;
	Bnode *left, *right;
	Bnode() { left=right=nullptr; }
	Bnode(int v) { val = v; left=right=nullptr; } 	// p is the next node
};

struct BST {
	size_t n, vn; 	// vn is for v's index in BST traverse
	int *v;
	Bnode *root;
	Bnode *freenode;	// problem 5
	Bnode *sentinel; 	// problem 7
	
	Bnode *rinsert(Bnode *p, int t) {
		if( p == nullptr ) {
			p = new Bnode(t);
			n++;
		} else if(t < p->val) {
			p->left = rinsert(p->left, t);
		} else if(t > p->val) {
			p->right = rinsert(p->right, t);
		} // do nothing if p->val == t
		return p;
	}
	void traverse(Bnode *p)
	{
		if(p == nullptr) 
			return;
		traverse(p->left);
		v[vn++] = p->val;
		traverse(p->right);
	}
	void deleteNode(Bnode *p) {
		// delete all nodes by post-order traverse
		if(p != nullptr) {
			deleteNode(p->left);
			deleteNode(p->right);
			//cout << "delete " << p->val << endl;
			delete p;
			p = nullptr;
		}
	}
	~BST() { deleteNode(root); }
};

class IntSetBST : public IntSet<BST> {
public:
	IntSetBST(int maxSize, int maxVal) {
		S.root = nullptr;
		S.n=0;
	}
	int size() { return S.n; }
	void insert(int t) { S.root = S.rinsert(S.root, t); }
	void report(int *v) { S.v = v; S.vn=0; S.traverse(S.root); }
};

// Problem 7
class IntSetBST2 : public IntSet<BST> {
public:
	IntSetBST2(int maxSize, int maxVal) {
		S.root = S.sentinel = new Bnode; 	// root = nullptr -> new
		S.n=0;
		S.freenode = new Bnode[maxSize]; 
	}
	int size() { return S.n; }
	void insert(int t) { 
		S.sentinel->val = t;
		Bnode **p = &(S.root);
		while( (*p)->val != t) {
			if( t < (*p)->val ) {
				p = &( (*p)->left);
			} else {
				p = &( (*p)->right );
			}
		}
		
		if( *p == S.sentinel) {
			*p = S.freenode++;
			(*p)->val = t;
			(*p)->left = (*p)->right = S.sentinel;
			S.n++;
		}
	}
	void report(int *v) { S.v = v; S.vn=0; S.traverse(S.root); }
};
#endif	// INTSET_LIST_H_
