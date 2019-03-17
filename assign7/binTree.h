#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "/home/cs340/progs/17f/p7/Node.h"

//*****************************************************************
//// FILE:      binTree.h
//// AUTHOR:    
//// LOGON ID:  
//// DUE DATE:  
//// PURPOSE:   
////*****************************************************************/

using namespace std;

template <class T>
class binTree
	{
	public:
		binTree();
		unsigned height() const;
		virtual void insert(const T&);
		void inorder(void(*)(const T&));
		unsigned size() const;
	
	protected:
		Node <T>* root;

	private:
		unsigned height(Node<T>*) const;
		void insert(Node <T>*&, const T&);
		void inorder(Node <T>*, void(*)(const T&));
		unsigned size(Node <T>*) const;
	};

//public recursive size method
template <class T>
unsigned binTree <T>::size() const
	{return size(root);}

//private size method to return size of tree
template <class T>
unsigned binTree <T>::size(Node <T>* ptr) const
	{
	if(ptr != 0)
		return 1 + size(ptr->left) + size(ptr->right);
	else
		return 0;
	}

typedef enum {left_side, right_side} SIDE;
SIDE rnd(){return rand()%2 ? right_side : left_side;}

//defualt constructor to initialize root
template <class T>
binTree <T>::binTree(){root = 0;}

//the following are public recurisve methods to call private methods of the same name
template <class T>
unsigned binTree <T>::height() const
	{return height(root);}

template <class T>
void binTree <T>::insert(const T& x)
	{insert(root, x);}

template <class T>
void binTree <T>::inorder(void(*x)(const T&))
	{inorder(root, x);}

//the following are private methods to be called by their public version
//determines height of tree
template <class T>
unsigned binTree <T>::height (Node <T>* ptr) const
	{
	if(ptr == 0 )
		//if Node ptr is 0 height is 0 so return 0
		return 0;
	else
		{
		int leftHeight = height(ptr->left);
		int rightHeight = height(ptr->right);
		
		//determines which side of the tree is longer and returns that +1 to include the root
		if(leftHeight > rightHeight)
			return 1+leftHeight;
		else
			return 1+rightHeight;
		}
	}

//inserts new node into tree
template <class T>
void binTree <T>::insert(Node <T>* &p, const T& x)
	{
	//inserts new node as root if pointer p is 0
	if(p == 0)
		{
		Node <T>* newNode;
		newNode = new Node <T>(x);
		p = newNode;
		}
	//randomly chooses a side of the tree and inserts number at the base of that side
	else
		{
		SIDE s = rnd();
		if(s == left_side)
			insert(p->left, x);
		else
			insert(p->right, x);
		}
	}

//traverses tree in order if the root is not null
template <class T>
void binTree <T>::inorder(Node <T>* p, void(*x)(const T&))
	{
	if(p != NULL)
		{
		inorder(p->left,x);
		x(p->data);
		inorder(p->right,x);
		}
	}

#endif
