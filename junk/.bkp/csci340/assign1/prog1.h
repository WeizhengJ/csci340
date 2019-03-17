#ifndef PROG1_H
#define PROG1_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

//*****************************************************************
//// FILE:      prog1.h
//// AUTHOR:    Damler, Lucas
//// LOGON ID:  z1761739
//// DUE DATE:  07 SEP 2017
//// PURPOSE:   Contains prototypes and declerations for prog1
////*****************************************************************/

using namespace std;

const int VEC_SIZE = 250;
const int LOW = 1;
const int HIGH = 10000;
const int NO_ITEMS = 12;

vector <int> v;
void genRanNum(vector <int>&);
void printVec(const vector <int>&);

#endif
