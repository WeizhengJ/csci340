#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"
#include <climits>

/*****************************************************************
 FILE:      binSTree.h
 AUTHOR:    Damler, Lucas
 LOGON ID:  z1761739
 DUE DATE:  02 NOV 2017
 PURPOSE:   implementation of a binary search tree for various data types
*****************************************************************/

template <class T>
class binSTree:public binTree<T>
	{
	public:
		void insert(const T& x);
		void remove(const T& x);
		unsigned min();

	private:
		void insert(Node<T>*&, const T&);
		void remove(Node<T>*&, const T&);
		void removeRt();
		unsigned min(Node <T>*);
		Node <T>* pred(Node<T>*);
	};

//public recursive insert method
template <class T>
void binSTree <T>::insert(const T& x)
	{insert(this->root, x);}

//public recursive remove method
template <class T>
void binSTree <T>::remove(const T& x)
	{remove(this->root, x);}

//private insert method
template <class T>
void binSTree <T>::insert(Node<T>*& ptr, const T& x)
	{
	//if empty make new node else compare item to insert to current place
	if(ptr == NULL)
		ptr = new Node <T>(x);
	else if(x < ptr->data)
		insert(ptr->left, x);
	else if(x > ptr->data)
		insert(ptr->right, x);
	else
		return;
	}

//private remove method
template <class T>
void binSTree<T>::remove(Node<T>*& ptr, const T& x)
	{
	if(ptr == NULL)
		return;
	else if(x < ptr->data)
		remove(ptr->left, x);
	else if(x > ptr->data)
		remove(ptr->right, x);
	else
		{
		Node <T>* temp = ptr;
		if(ptr->right == NULL)
			ptr = ptr->left;
		else if(ptr->left == NULL)
			ptr = ptr->right;
		else
			{
			unsigned minVal = min(ptr->right);
			remove(ptr->right, minVal);
			ptr->data = minVal;
			return;
			}
		delete temp;
		}
	}

//public recursive min method
template <class T>
unsigned binSTree<T>::min()
	{return min(this->root);}

//private min method. returns min pointer to node
template <class T>
unsigned binSTree<T>::min(Node <T>* ptr)
	{
	if(ptr == NULL)
		return INT_MIN;
	if(ptr->left != NULL)
		return min(ptr->left);

	return ptr->data;
	}

template <class T>
Node <T>* binSTree <T>::pred(Node <T>* ptr)
	{
	while(ptr->right)
		ptr = ptr->right;
	return ptr;
	}

#endif
