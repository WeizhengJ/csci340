/*********************************************************************
    PROGRAM:    CSCI 340 Assignment 1
    PROGRAMMER: 
    LOGON ID:   
    DUE DATE:   
    PURPOSE:    
 **********************************************************************/

#include "prog1.h"

/***************************************************************
Function: main()
Use: main function to call other methods
Parameters: none
Returns: nothing
***************************************************************/

int main()
	{
	genRanNum(v);
	sort(v.begin(), v.end());
	printVec(v);
	}

/***************************************************************
Function: genRanNum()
Use: generates random numbers into a vector
Parameters: v: a reference to a vector defined in the header file
Returns: nothing
***************************************************************/

void genRanNum(vector <int>& v)
	{
	srand((unsigned)time(NULL));
	for(unsigned int i = 0; i < VEC_SIZE; i++)
		{
		int temp = rand()%(HIGH-LOW+1)+LOW;
		v.push_back(temp);
		}
	}

/***************************************************************
Function: printVec()
Use: displays numbers stored in vector
Parameters: v: a reference to a vector defined in the header file
Returns: nothing
***************************************************************/

void printVec(const vector <int>& v)
	{
	for(unsigned int i = 0; i < VEC_SIZE; i++)
		{
		cout << setw(6) << right << v[i];
		if((i+1)%12 == 0){cout << endl;}
		}
	cout << endl << endl;
	}
