/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p15.cpp
Author: rbee3u
Date: 2016/1/23
Description: https://projecteuler.net/problem=15
******************************************************************************/
#include <iostream>
#include <cstdint>
using namespace std;

int main() {
	uint64_t ans = 1;
	for (uint64_t x=1; x <= 20; ++x) {
		ans = ans * (41-x) / x;
	}
	cout << ans << endl;
	return 0;
}

