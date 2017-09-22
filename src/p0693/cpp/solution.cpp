#include <iostream>

class Solution {
public:
    bool hasAlternatingBits(unsigned n) {
        n = (n ^ (n >> 1)) + 1;
        return (n & -n) == n;
    }
};
