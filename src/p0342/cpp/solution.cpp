#include <iostream>


class Solution {
public:
    bool isPowerOfFour(int x) {
        return (x > 0) && x == (x & -x & 0x55555555);
    }
};
