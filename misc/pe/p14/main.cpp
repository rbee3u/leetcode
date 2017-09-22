/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p14.cpp
Author: rbee3u
Date: 2016/1/23
Description: https://projecteuler.net/problem=14
******************************************************************************/
#include <iostream>
#include <cstdint>
using namespace std;

const uint64_t MAXN = 1000000;
uint64_t chain[MAXN] = {0,1};

uint64_t getLength(uint64_t x) {
	uint64_t y = x, s = 0;
	for (; ; ++s) {
		if (y<MAXN && chain[y]) {
			s += chain[y]; break;
		}
		if (y%2==1) {
			y = (3*y+1);
		} else {
			y = y / 2;
		}
	}
	y = x;
	for (; ; ) {
		if (y < MAXN) {
			if (!chain[y]) {
				chain[y] = s;
				--s;
			}
		}
		if (y<MAXN && chain[y]) {
			break;
		}
	}
}

int main() {
	uint64_t ans = 0, val = 0, tmp;
	for (uint64_t x = 1; x < MAXN; ++x) {
		tmp = getLength(x);
		if (ans < tmp) {
			ans = tmp;
			val = x;
		}
	}
	cout << val << endl;
	return 0;
}

