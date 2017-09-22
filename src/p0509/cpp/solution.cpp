#include <iostream>


class Solution {
public:
    int fib(int x) {
        assert(0 <= x && x <= 30);
        auto n = unsigned(x);
        auto m = n | n >> 1U;
        m |= m >> 2U;
        m |= m >> 4U;
        m ^= m >> 1U;

        int a = 1, b = 0, t = 1;
        for (; m; m >>= 1U, t = a) {
            if (m & n) {
                a *= t + b + b;
                b = t * t + b * b;
            } else {
                a = t * t + b * b;
                b *= t + t - b;
            }
        }
        return b;
    }
};
