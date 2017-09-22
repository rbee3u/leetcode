#include <iostream>

class Solution {
public:
    int integerReplacement(unsigned n) {
        int result = 0;
        while (n > 3) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 4 == 1) {
                n--;
            } else {
                n++;
            }
            result++;
        }
        return result + (n - 1);
    }
};
