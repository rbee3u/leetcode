/******************************************************************************
Copyright (C), 2016, rbee3u
FileName: p7.cpp
Author: rbee3u
Date: 2016/1/20
Description: https://projecteuler.net/problem=7
******************************************************************************/
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

template<typename T> class PrimeTable {
private:
	vector<uint32_t> array; vector<T> plist;
	void setf(T n) {array[n/32] &= ~(1<<(n%32));}
public:
	bool isPrime(T n) {return (array[n/32]&(1<<(n%32)));}
	T getPrime(T idx) {return plist[idx];}
	T getLimit() {return (array.size() * 32);}
	T getCount() {return (plist.size() - 1);}
	PrimeTable(T limit) {
		limit = (limit+31) / 32 * 32;
		array.resize(limit / 32, -1);
		setf(0); setf(1); T d, n;
		for (d=2; d*d<limit; ++d) if(isPrime(d)) {
			for (n=d+d; n<limit; n+=d) {setf(n);}
		}
		plist.push_back(0); for (n=1; n<limit; ++n) {
			if (isPrime(n)) {plist.push_back(n);}
		}
	}
};

int main() {
	PrimeTable<int> pt(1000000);
	cout << pt.getPrime(10001) << endl;
	return 0;
}

