#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int> nums) {
        size_t j = 0, i = 0, n = nums.size();
        for (j = 0, i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[j], nums[i]); j++;
            }
        }
        return nums;
    }
};
