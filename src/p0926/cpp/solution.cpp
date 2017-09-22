#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int f0 = 0, f1 = 0;
        for (auto c : s) {
            if (c == '0') {
                f1 = min(f0 + 1, f1 + 1);
            } else {
                f1 = min(f0, f1);
                f0 = f0 + 1;
            }
        }
        return min(f0, f1);
    }
};
