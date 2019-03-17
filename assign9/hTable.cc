#ifndef TABLE_H
#define TABLE_H

#include "/home/cs340/progs/17f/p9/hTable.h"

//*****************************************************************
//// FILE:      
//// AUTHOR:    Damler, Lucas
//// LOGON ID:  z1761739
//// DUE DATE:  28 NOV 2017
//// PURPOSE:   
////*****************************************************************/

#define OPEN "empty"

using namespace std;

HT::HT(cosnt unsigned& hs)
	{
	hTable.resize(hs);

	hsize = TBLSZ;

	for(unsigned i = 0; i != hs; i++)
		hTable[i].key = OPEN;
	}

HT::~HT(){}

void HT::insert(const Entry& e)
	{
	unsigned idx = hash(e.key);
	unsigned i;
	for(i = 0; i < hsize; i++)
		{
		if(hTable[(idx+i)%hsize].key == OPEN)
			{
			cout << "Entry is " << (idx+i)%hsize << endl;
			hTable[(idx+i)%hsize] = e;
			break;
			}
		if(hTable[(idx+i)%hsize].key == e.key)
			{
			cout << "ERROR IS DUPLICATE\n";
			break;
			}
		}

	if(i == hsize)
		cout << "ERROR NOT INSERTED - TABLE FULL\n";
	}

void HT::search(const string& key)
	{
	unsigned idx = hash(key);
	unsigned i;
	for(i = 0; i < hsize; i++)
		{
		if(hTable[(idx+i)%hsize].key == key)
			{
			cout << "NUMBER: " << setw(4) << hTable[(idx+i)%hsize].num
			     << " - ITEM: " << hTable[(idx+I)%hsize].desc << endl;
			break;
			}
		}

	if(hTable[(idx+i)%hsize].key != key)
		cout << " NOT IN TABLE\n";
	}

void HT::hTable_print()
	{
	bool lastEmpty = false;
	for ( unsigned int i = 0; i < hsize; i++ )
	{
		if ( hTable[i].key != OPEN)
		{
			if ( lastEmpty ) cout << endl;
			cout << setw(4) << i << ":  " << hTable[i].key << " - "
			<< setw(5) << hTable[i].num << "   -  " << hTable[i].desc << endl;
			lastEmpty = false;
		}
		else lastEmpty = true;
	}
	cout << endl;
	}

void HT::pTable_print ( )
{
	sort(pTable.begin(), pTable.end(), cmp(Entry* p, Entry* q));
	for (unsigned int i = 0; i < psize; i++ )
	{
		cout << "   " << pTable[i]->key
		<< " - " << right << setw(4) << pTable[i]->num
		<< " - " << left << pTable[i]->desc << endl;
	}
	cout << endl;
}

#endif
