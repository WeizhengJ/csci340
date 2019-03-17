#ifndef PROG1_H
#define PROG1_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

//*****************************************************************
//// FILE:      prog2.h
//// AUTHOR:    
//// LOGON ID:  
//// DUE DATE:  
//// PURPOSE:   
////*****************************************************************/

using namespace std;

const int ARR_SIZE = 200, TEST_ARR_SIZE = 100;
const int ITEM_W = 4, NO_ITEMS = 16;
const int LOW = 1, HIGH = 1000;
const int SEED1 = 1, SEED2 = 3;

void Vectors(vector <int>&, vector <int>&, int, int);
bool linearSearch(const vector <int>&, int);
bool binarySearch(const vector <int>&, int);
int search(const vector <int>&, const vector <int>&, bool (*p)( const vector < int >&, int ));
void sortVector(vector <int>&);
void printVector(const vector <int>&);
void printStat(int, int);

#endif
