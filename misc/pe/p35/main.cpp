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


int rotate(int x, int m) {
    return (x % m) * 10 + (x / m);
}


bool is_circular(int x) {
    int m = 10;
    while (m <= x) {
        m *= 10;
    }
    m /= 10;
    int y = x;
    do {
        if (!pt.isPrime(y)) {
            return false;
        }
        y = rotate(y, m);
    } while (y != x);
    return true;
}


int main() {
    int ans = 0;
    for (int x = 2; x < 1000000; ++x) {
        if (is_circular(x)) {
            ++ans;
            // cout << x << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

