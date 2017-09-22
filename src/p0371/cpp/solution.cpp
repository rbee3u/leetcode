#include <iostream>

class Solution {
public:
    int getSum(int a, int b) {
        unsigned x = a, y = b, t;
        for (; y; ) {
            t = x & y;
            x ^= y;
            y = t << 1;
        }
        return x;
    }
};
