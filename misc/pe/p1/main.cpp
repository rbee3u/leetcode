/******************************************************************************
Copyright (C), 2015, rbee3u
FileName: p1.cpp
Author: rbee3u
Date: 2015/10/27
Description: https://projecteuler.net/problem=1
******************************************************************************/
#include <stdio.h>

int main()
{
	int n = 1000, sum = 0;
	for (int i=1; i < n; ++i) {
		if (0==i%3 || 0==i%5) {
			sum += i;
		}
	}
	printf("%d\n", sum);
	return 0;
}

