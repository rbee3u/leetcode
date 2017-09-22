#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) {
            return (X - Y);
        }
        int H = (Y + 1) / 2;
        if (X >= H) {
            return (X - H) + 1 + Y % 2;
        }
        return brokenCalc(X, H) + 1 + Y % 2;
    }
};
