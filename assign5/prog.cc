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

int main()
	{
	struct inargs in;
	vector <string> v;
	init_vals(v, in);
	unsigned int j = 0, i = 0, cnt = 0;
	
	for(j, i; v.size() > 1; j++,i++)
		{
		if(i >= v.size())
			i = 0;

		if(j == in.M)
			{
			v.erase(v.begin()+(i));
			j = 0;
			}
		}
	print_vector(v,cnt);
	}

void init_vals(vector <string>& v, struct inargs& in)
	{
	cout << "N: ";
	cin >> in.N;
	cout << "M: ";
	cin >> in.M;
	cout << "K: ";
	cin >> in.K;

	v.resize(in.N);
	generate(v.begin(), v.end(), SEQ(in.N));

	cout << "Initial:\n";
	//print_vector(v, 0);
	}

void print_vector(const vector <string>& v, const unsigned& cnt)
	{
	cout << "Vector: " << cnt << endl;
	int newLine = 1;
	vector <string>::const_iterator it;
	for(it = v.begin(); it != v.end(); it++)
		{
		cout << *it << " ";
		if(newLine == 12)
			{
			cout << endl;
			newLine = 0;
			}
		newLine++;
		}	
	cout << endl;
	}
