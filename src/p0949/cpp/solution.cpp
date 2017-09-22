#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


class Solution {
public:
    string largestTimeFromDigits(vector<int> &digits) {
        sort(digits.begin(), digits.end());
        for (int i = 3; i >= 0; i--) {
            if (digits[i] > 2) continue;
            for (int j = 3; j >= 0; j--) {
                if (j == i) continue;
                int h = digits[i] * 10 + digits[j];
                if (h > 23) continue;
                for (int p = 3; p >= 0; p--) {
                    if (p == i || p == j) continue;
                    if (digits[p] > 5) continue;
                    for (int q = 3; q >= 0; q--) {
                        if (q == i || q == j || q == p) continue;
                        int m = digits[p] * 10 + digits[q];
                        stringstream result;
                        result << digits[i] << digits[j]
                               << ":"
                               << digits[p] << digits[q];
                        return result.str();
                    }
                }
            }
        }
        return "";
    }
};
