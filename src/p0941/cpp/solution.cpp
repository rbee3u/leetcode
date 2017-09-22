#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int> &nums) {
        int up = 0, down = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (down == 0 && nums[i - 1] < nums[i]) {
                up++;
            } else if (up && nums[i - 1] > nums[i]) {
                down++;
            } else {
                return false;
            }
        }
        return up > 0 && down > 0;
    }
};
