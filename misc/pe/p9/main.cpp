/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p9.cpp
Author: rbee3u
Date: 2016/1/20
Description: https://projecteuler.net/problem=9
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	for (a = 1; a <= 333; ++a) {
		for (b = a+1; b <= 666; ++b) {
			c = 1000 - a - b;
			if (a*a + b*b == c*c) {
				cout << a << "^2 + " << b << "^2 = " << c << "^2" << endl;
				cout << a*b*c << endl;
				goto end;
			}
		}
	}
	
	end:
	return 0;
}

