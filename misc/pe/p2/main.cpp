/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p2.cpp
Author: rbee3u
Date: 2016/1/20
Description: https://projecteuler.net/problem=2
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	int sum=0, a=0, b=1;
	for (; b <= 4000000; ) {
		if (b%2==0) sum += b;
		b = b + a; a = b - a;
	}
	cout << sum << endl;
	return 0;
}

