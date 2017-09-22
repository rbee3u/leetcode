#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int> &nums) {
        int up = 0, down = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            up   += nums[i - 1] < nums[i];
            down += nums[i - 1] > nums[i];
        }
        return up == 0 || down == 0;
    }
};

