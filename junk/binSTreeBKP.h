#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"

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

	private:
		void insert(Node<T>*&, const T&);
		void remove(Node<T>*&, const T&);
		void removeRt();
		Node <T>* pred(Node<T>*);
	};

template <class T>
void binSTree <T>::insert(const T& x)
	{insert(this->root, x);}

template <class T>
void binSTree <T>::remove(const T& x)
	{remove(this->root, x);}

template <class T>
void binSTree <T>::insert(Node<T>*& ptr, const T& x)
	{
	if(ptr == NULL)
		ptr = new Node <T>(x);
	else if(x < ptr->data)
		insert(ptr->left, x);
	else if(x > ptr->data)
		insert(ptr->right, x);
	else
		return;
	}

template <class T>
void binSTree<T>::remove(Node<T>*& ptr, const T& x)
	{
	bool found = false;
	Node <T>* pred = NULL;
	Node <T>* cur = ptr;

	if(cur == NULL)
		cout << "EMPTY TREE\n";
	while(cur != NULL)
		{
		if(cur->data == x)
			{
			found = true;
			break;
			}
		else
			{
			pred = cur;
			if(x > (cur->data))
				cur = cur->right;
			else
				cur = cur->left;
			}
		}
	if(!found)
		return;
	if((cur->left == NULL && cur->right != NULL) || (cur->left != NULL && cur->right ==NULL))
		{
		if(cur->left == NULL && cur->right != NULL)
			{
			if(pred->left == cur)
				{
				pred->left = cur->right;
				delete cur;
				cur = NULL;
				}
			else
				{
				pred->right = cur->right;
				delete cur;
				cur = NULL;
				}
			}
		else
			{
			if(pred->left == cur)
				{
				pred->left = cur->left;
				delete cur;
				cur = NULL;
				}
			else
				{
				pred->right = cur->left;
				delete cur;
				cur = NULL;
				}
			}
		}
	if(cur->left == NULL && cur->right == NULL)
		{
		if(pred->left == cur)
			pred->left = NULL;
		else
			pred->right = NULL;
		delete cur;
		}
	if((cur->left != NULL) && (cur->right != NULL))
		if((cur->left == NULL) && (cur->right == NULL))
			{
			Node <T>* delNode = cur->right;
			cur = delNode;
			delete delNode;
			cur->right = NULL;
			}
		else
			{
			if((cur->right)->left != NULL)
				{
				Node <T>* leftCur;
				Node <T>* leftCurPred = cur->right;
				leftCur = (cur->right)->left;
				while(leftCur->left != NULL)
					{
					leftCurPred = leftCur;
					leftCur = leftCur->left;
					}
				cur->data = leftCur->data;
				delete leftCur;
				leftCurPred->left = NULL;
				}
			else
				{
				Node <T>* temp = cur->right;
				cur->data = temp->data;
				cur->right = temp->right;
				delete temp;
				}
			}
	}

template <class T>
Node <T>* binSTree <T>::pred(Node <T>* ptr)
	{
	while(ptr->right)
		ptr = ptr->right;
	return ptr;
	}

#endif
