#include <iostream>


class Solution {
public:
    bool isPalindrome(int x) {
        if (x > 0 && x % 10 == 0) {
            return false;
        }
        int y = 0;
        for (; y < x; x /= 10) {
            y = y * 10 + x % 10;
            if (x == y) break;
        }
        return x == y;
    }
};
