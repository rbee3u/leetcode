#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int result = 0, i = 0;
        for (auto x : nums) {
            result ^= x ^ (++i);
        }
        return result;
    }
};
