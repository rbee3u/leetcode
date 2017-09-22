#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        bool modified = false;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (modified) return false;
                if (i > 1 && nums[i - 2] > nums[i]) {
                    nums[i] = nums[i - 1];
                }
                modified = true;
            }
        }
        return true;
    }
};
