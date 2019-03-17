#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include "/home/cs340/progs/17f/p5/prog5.h"

//*****************************************************************
//// FILE:      prog5.cc
//// AUTHOR:    
//// LOGON ID:  
//// DUE DATE:  
//// PURPOSE:   
////*****************************************************************/

using namespace std;

/***************************************************************
 * Function: main()
 * Use: main driver function
 * Parameters: None
 * Returns: nothing
 ***************************************************************/ 

int main()
	{
	struct inargs in;
	vector <string> v;
	unsigned i = -1, cnt = 0;
	init_vals(v, in);

	print_vector(v, cnt);

	while(v.size() > 1)
		{
		cnt++;
		i = (i+in.M)%v.size();

		v.erase(v.begin()+(i));

		--i;

		if(cnt%in.K == 0)
			print_vector(v,cnt);
		}
	print_vector(v,cnt);
	}

/***************************************************************
 * Function: init_vals()
 * Use: initializes inargs values and generates soldiers into vecotr
 * Parameters: v: string vector reference to hold soldier names
 * 	       in: inargs struct reference to hold input values
 * Returns: nothing
 ***************************************************************/

void init_vals(vector <string>& v, struct inargs& in)
	{
	cin >> in.N >> in.M >> in.K;
	cout << "Number of perople? " << in.N << endl;
	cout << "Index for elimination? " << in.M << endl;
	cout << "Index for printing? " << in.K << endl;
	
	cout << endl;

	v.resize(in.N);
	generate(v.begin(), v.end(), SEQ(in.N));
	}

/***************************************************************
 * Function: print_vector()
 * Use: prints passed in vector
 * Parameters: v: const string vector to print
 * 	       cnt: unsigned int that contains the removed count
 * Returns: nothing
 ***************************************************************/

void print_vector(const vector <string>& v, const unsigned& cnt)
	{
	if(cnt > 0)
		{
		cout << "After eliminating the " << cnt << "th person\n";
		cout << "---------------------------------\n";
		}
	else
		{
		cout << "Initial group of people\n";
		cout << "-----------------------\n";
		}

	int newLine = 1;
	vector <string>::const_iterator it;
	for(it = v.begin(); it != v.end(); it++)
		{
		cout << *it << " ";
		if(newLine == NO_ITEMS)
			{
			cout << endl;
			newLine = 0;
			}
		newLine++;
		}	
	cout << endl << endl;
	}
