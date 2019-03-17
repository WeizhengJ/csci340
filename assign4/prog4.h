#ifndef PROG4_H
#define PROG4_H

#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>

//*****************************************************************
//// FILE:      prog4.h
//// AUTHOR:    
//// LOGON ID:  
//// DUE DATE:  
//// PURPOSE:   
////*****************************************************************/

using namespace std;

const int ITEM_W = 16;
const int NO_ITEM = 3;

void get_words(map <string, int>&);
void print_words(const map<string, int>);
void clear_entry(const string&, string&);
void lower(char&);

/***************************************************************
 * Function: get_words
 * Use: gets word input for map container
 * Parameters: m: map container to hold input strings
 * Returns: nothing
 * ***************************************************************/

void get_words(map <string, int>& m)
	{
	string first, s;
	while(cin >> first)
		{
		clear_entry(first,s);
		if(s.length() != 0)
			{
			m[s]++;
			}
		}
	}

/***************************************************************
 * Function: print_words
 * Use: prints passed in map container
 * Parameters: m: map container to be printed
 * Returns: nothing
 * ***************************************************************/

void print_words(const map <string, int> m)
	{
	int words = 0, newLine = 1;

	for(auto i = m.begin(); i != m.end(); i++)
		{
		cout << setw(ITEM_W) << left << i->first << " : " << i->second << "\t";
		if(newLine == NO_ITEM)
			{
			cout << endl;
			newLine = 0;
			}

		newLine++;
		words+=i->second;
		}

	cout << "\nTotal words: " << words << endl;
	cout << "Displayed words: " << m.size() << endl;
	}

/***************************************************************
 * Function: clear_entry
 * Use: remove puncation from a string and store in another string
 * Parameters: word: string reference to remove puncuation from
 * 	       s: string reference to store cleaned word
 * Returns: nothing
 * ***************************************************************/

void clear_entry(const string& word, string& s)
	{
	size_t i = 0, j = 0;
	for(i = 0; i < word.length(); i++)
		if(isalnum(word[i])){break;}

	for(j = i; j < word.length(); j++)
		if(!isalnum(word[j])){break;}

	s = word.substr(i,j-i);
	for_each(s.begin(), s.end(), lower);
	}

void lower(char& c){c = tolower(c);}

#endif
