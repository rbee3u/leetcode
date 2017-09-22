#include <iostream>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = (dividend < 0) == (divisor < 0);
        switch (divisor) {
        case    0: return IMAX;
        case   -1: return dividend == IMIN ? IMAX : -dividend;
        case IMIN: return dividend == IMIN;
        default:   divisor = abs(divisor);
        }
        if (dividend == IMIN) {
            if (divisor == 1) return IMIN;
            if ((dividend & 1) || (divisor & 1)) {
                dividend = IMAX;
            } else {
                dividend = HALF; divisor >>= 1;
            }
        } else {
            dividend = abs(dividend);
        }
        int quotient = 0;
        for (int i = 31; i >= 0; i--) {
            if ((dividend >> i) >= divisor) {
                quotient += 1 << i;
                dividend -= divisor << i;
            }
        }
        return positive ? quotient : -quotient;
    }

private:
    static const int IMIN = -0x80000000;
    static const int IMAX =  0x7fffffff;
    static const int HALF =  0x40000000;
};
