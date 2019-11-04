#pragma once
#include<iostream>
#include<algorithm>

using std::string;
using std::sort;

int* check(string* cards);
bool strightCheck(short(*cardVals)[2]);
bool flushCheck(short(*cardVals)[2]);
int TopCheck(short(*cardVals)[2]);