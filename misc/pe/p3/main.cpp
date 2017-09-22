/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p3.cpp
Author: rbee3u
Date: 2016/1/20
Description: https://projecteuler.net/problem=3
******************************************************************************/
#include <iostream>
using namespace std;

int main() {
	long long n = 600851475143;
	long long d, ans;
	for (d=2; d*d <= n; ++d) {
		if (n%d == 0) {
			ans = d;
			for (; n%d==0; n/=d);
		}
	}
	if (n > 1) {
		cout << n << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}

