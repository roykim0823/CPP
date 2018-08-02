/*
 * SLList.h
 *
 *  Created on: 2011-11-25
 *      Author: morin
 *       FIXME: This code is completely untested (but was ported from tested Java code)
 */

#ifndef SLLIST_H_
#define SLLIST_H_
#include <stdlib.h>

namespace ods {

template<class T>  	
class SLList {	// Single-Linked List, a sequence of Nodes
	T null;  // For the NULL value
protected:
	// 
	class Node {
	public:
		T x;		// Data
		Node *next;	// Link
		Node(T x0) { 	// Constructor
			x = x0; 	// rev from: x=0
			next = NULL;
		}
	};
	// For efficiency, SLList uses head and tail to keep track of the first and the last node
	Node *head; 	// Head node
	Node *tail;   	// Tail node: to implement add() function 
	int n;         	// Size, the length of the sequence

public:

	SLList() {
		null = (T)NULL;
		n = 0;
		head = tail = NULL;
	}

	virtual ~SLList() {
		Node *u = head;
		while (u != NULL) {
			Node *w = u;
			u = u->next;
			delete w;
		}
	}

	int size() {
		return n;
	}

	T peek() {
		return head->x;
	}

	// add at the end of the list
	bool add(T x) {
		Node *u = new Node(x);
		if (n == 0) {
			head = u;	// head points to the new node if the list is empty
		} else {
			tail->next = u; // tail points to the new node 
		}
		tail = u;	// move the tail to the new node
		n++;
		return true;
	}

	// push on the head
	T push(T x) {
		Node *u = new Node(x);
		u->next = head;	// new node points to the first node that head pointer points
		head = u;       // the head points to the new node
		if (n == 0)     
			tail = u;   // the tail points to the new node if this is the fist node
		n++;
		return x;
	}

	// remove on the head, same as pop()
	T remove() {
		if (n == 0)	return null;
		T x = head->x;	// copy first node's value
		Node *u = head;	// u points to the node that will be deleted	
		head = head->next;
		delete u;
		if (--n == 0) tail = NULL;
		return x;
	}

	// pop on the head 
	T pop() {
		if (n == 0)	return null;	
		T x = head->x;	// copy the head to return it
		Node *u = head; // copy the head node to temporary to remove
		head = head->next;	
		delete u;       // remove the node
		if (--n == 0) tail = NULL;	// if the node becomes empty, tail points to NULL
		return x;
	}


};

} /* namespace ods */
#endif /* SLLIST_H_ */
