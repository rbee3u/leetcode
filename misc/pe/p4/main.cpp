/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p4.cpp
Author: rbee3u
Date: 2016/1/20
Description: https://projecteuler.net/problem=4
******************************************************************************/
#include <iostream>
using namespace std;

bool is_palindrome(int x) {
	int y = 0;
	for (int n=x; n; n /= 10) {
		y = y*10 + n%10;
	}
	return (x == y);
}

int main() {
	int ans = 0;
	for (int a=100; a <= 999; ++a) {
		for (int b=100; b <= 999; ++b) {
			int c = a * b;
			if (is_palindrome(c) && (ans < c)) {
				ans = c;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

