/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p6.cpp
Author: rbee3u
Date: 2016/1/20
Description: https://projecteuler.net/problem=6
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	int n = 100;
	cout << n*n*(n+1)*(n+1)/4 - n*(n+1)*(2*n+1)/6 << endl;
	return 0;
}

