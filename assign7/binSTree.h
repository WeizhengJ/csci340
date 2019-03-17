#ifndef BINSTREE_H
#define BINSTREE_H

#include "binTree.h"

/*****************************************************************
 FILE:      binSTree.h
 AUTHOR:    
 LOGON ID:  
 DUE DATE:  
 PURPOSE:   
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

/***************************************************************
 * Method: insert()
 * Use: determines where to insert an item into a binary tree
 * Parameters: ptr: pointer to a node of type T
 *             x: const reference to type T data type
 * Returns: nothing
***************************************************************/ 
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

/***************************************************************
 * Method: insert()
 * Use: determines what items to remove in a binary tree
 * Parameters: ptr: pointer to a node of type T
 *             x: const reference to type T data type
 * Returns: nothing
***************************************************************/
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
		if(ptr->left == NULL && ptr->right == NULL)
			{
			delete ptr;
			ptr = NULL;
			}

		else if(ptr->left == NULL || ptr->right == NULL)
			{
			if(ptr->left == NULL)
				{
				Node <T>* temp = ptr;
				ptr = ptr->left;
				delete temp;
				}
			if(ptr->right == NULL)
				{
				Node <T>* temp = ptr;
				ptr = ptr->left;
				delete temp;
				}
			return;
			}
		else
			{
			Node <T>* temp = pred(ptr);
			ptr->data = temp->data;
			remove(ptr->left, temp->data);
			}
		}
	}

//private pred method to find the predecessor node
template <class T>
Node <T>* binSTree <T>::pred(Node <T>* ptr)
	{
	while(ptr->right)
		ptr = ptr->right;
	return ptr;
	}

#endif
