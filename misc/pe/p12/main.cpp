/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p12.cpp
Author: rbee3u
Date: 2016/1/23
Description: https://projecteuler.net/problem=12
******************************************************************************/
#include <iostream>
using namespace std;
typedef long long int LLI;

int tau(int n) {
	int ret = 1, tmp;
	for (int d=2; d*d<=n; ++d) if (n%d==0) {
		for (tmp=1; n%d==0; n/=d) {++tmp;}
		ret *= tmp;
	} if (n > 1) {ret *= 2;}
	return ret;
}

int main() {
	// for (int x=1; x < 10; ++x) {
	// 	cout << tau(x) << endl;
	// }
	for (int i=1; ; ++i) {
		int x, y;
		if (i%2==0) {
			x = i / 2;
			y = i + 1;
		} else {
			x = i;
			y = (i+1)/2;
		}
		if (tau(x)*tau(y) > 500) {
			cout << LLI(x)*y << endl;
			break;
		}
	}
	return 0;
}

