#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool hasGroupsSizeX(vector<int> &cards) {
        unordered_map<int, int> counts;
        for (auto card : cards) {
            counts[card]++;
        }
        int g = 0;
        for (auto &count : counts) {
            g = gcd(count.second, g);
        }
        return g >= 2;
    }

private:
    int gcd(int n, int m) {
        for (int t; m > 0; ) {
            t = m; m = n % m; n = t;
        }
        return n;
    }
};
