#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
        bool negative = n < 0;
        double y = 1, p = x;
        for (; n != 0; p *= p, n /= 2) {
            if (n % 2 != 0) { y *= p; }
        }
        return negative ? 1 / y : y;
    }
};
