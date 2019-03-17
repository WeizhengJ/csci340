/*********************************************************************
    PROGRAM:    CSCI 340 Assignment 3
    PROGRAMMER: 
    LOGON ID:   
    DUE DATE:   
    PURPOSE:    
 **********************************************************************/

#include "prog3.h"

/***************************************************************
Function: main()
Use: call program methods
Parameters: none
Returns: nothing
***************************************************************/
int main()
	{
	int n;
	set <int> s;
	cout << "designate upper bound: ";
	cin >> n;

	sieve(s, n);
	print_primes(s);

	return 0;
	}

/***************************************************************
 * Function: sieve()
 * Use: store n numbers in a set and remove all non prime integers
 * Parameters: s: set container for integers
 * 	       n: int for size of set container
 * Returns: nothing
 * ***************************************************************/
void sieve(set <int>& s, int n)
	{
	for(int i = 2; i <= n; i++)
		s.insert(i);

	for(int m = 2; m < *s.rbegin(); m++)
		{
		for(int k = m; k < n; k++)
			s.erase(m*k);
		}
	}

/***************************************************************
 * Function: print_primes()
 * Use: prints set containing prime numbers
 * Parameters: s: set containing prime numbers
 * Returns: nothing
 * ***************************************************************/
void print_primes(const set <int>& s)
	{
	int newLine = 1;
	typedef set <int>::iterator sIt;
	for(sIt i = s.begin(); i != s.end(); ++i)	
		{
		cout << setw(ITEM_W) << right << *i << " ";
			if(newLine == NO_ITEMS)
				{
				cout << endl;
				newLine = 0;
				}
			newLine++;
		}
	        cout << endl << endl;
	}
