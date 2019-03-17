/*********************************************************************
    PROGRAM:    CSCI 340 Assignment 2
    PROGRAMMER: 
    LOGON ID:   
    DUE DATE:   
    PURPOSE:    
 **********************************************************************/

#include "prog2.h"

/***************************************************************
Function: Vectors()
Use: fill passed vectors with pseudo-random numbers
Parameters: v1,v2: vectors of integers
	    s1,s2; int representing the seed number
Returns: nothing
***************************************************************/

void Vectors(vector <int>& v1, vector <int>& v2, int s1, int s2)
	{
	srand(s1);
	for(size_t i = 0; i < ARR_SIZE; i++)
		{
		int temp = rand()%(HIGH-LOW+1)+LOW;
		v1[i] = temp;
		}

	srand(s2);
	for(size_t i = 0; i < TEST_ARR_SIZE; i++)
		{
		int temp = rand()%(HIGH-LOW+1)+LOW;
		v2[i] = temp;
		}
	}

/***************************************************************
 Function: linearSearch()
 Use: does a linear search on passed in vector
 Parameters: v: vector int to be searched
 	     x: int to be searched for
 Returns: true or false
***************************************************************/

bool linearSearch(const vector <int>& v, int x)
	{
	vector <int>::const_iterator it;
	it = find(v.begin(), v.end(), x);
	if(it != v.end())
		return true;
	else
		return false;
	}

/***************************************************************
 * Function: binarySearch()
 * Use: does a binary search on passed in vector
 * Parameters: v: vector int to be searched
 *             x: int to be searched for 
 * Returns: true or false
 * ***************************************************************/

bool binarySearch(const vector <int>& v, int x)
	{
	if(binary_search(v.begin(), v.end(), x))
		return true;
	else
		return false;
	}

/***************************************************************
 * Function: search()
 * Use: keeps track of search count
 * Parameters: v1,v2: vector int to be tracked for search
 * 	       *p: bool pointer to an argument
 * Returns: count
 * ***************************************************************/

int search (const vector <int>& v1, const vector <int>& v2, bool (*p) (const vector <int>&, int))
	{
	size_t count = 0;
	for(size_t i = 0; i < v2.size(); i++)
		{
		if(p(v1,v2[i]))
		count++;
		}
	return count;
	}

/***************************************************************
 * Function: sortVector()
 * Use: sorts passed in vector
 * Parameters: v: vector int to be sorted
 * Returns: nothing
 * ***************************************************************/

void sortVector(vector <int>& v)
	{
	sort(v.begin(), v.end());
	}

/***************************************************************
 * Function: printVector()
 * Use: prints passed in vector
 * Parameters: v: const vector to be printed
 * Returns: nothing
 * ***************************************************************/

void printVector(const vector <int>& v)
	{
	for(size_t i = 0; i < v.size(); i++)
		{
		cout << setw(ITEM_W) << right << v[i];
		if((i+1)%NO_ITEMS == 0)
			cout << endl;
		}
	cout << endl << endl;
	}

/***************************************************************
 * Function: printStat()
 * Use: prints stats of successful counts
 * Parameters: totalSucCnt: total number of successful counts
 * 	       vectorSz: size of vector counted
 * Returns: nothing
 * ***************************************************************/

void printStat(int totalSucCnt, int vectorSz)
	{
	double perc = (double)totalSucCnt/vectorSz;
	cout << setprecision(2) << fixed << "\tSuccess count percentage: "  << perc*100 << "%\n";
	}
