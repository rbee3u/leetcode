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

PrimeTable<int> pt(2000000);

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    return pt.isPrime(x);
}

int length(int a, int b) {
    int n = 0;
    while (1) {
        if (!is_prime(n*n+n*a+b)) {
            break;
        }
        ++n;
    }
    return n;
}


int main() {
	int max_length = 0, max_product = 0;
	for (int a = -999; a <= 999; ++a) {
		for (int b = -999; b <= 999; ++b) {
			int len = length(a, b);
			if (len > max_length) {
				max_length = len;
				max_product = a * b;
			}
		}
	}
    cout << max_product << endl;
    return 0;
}