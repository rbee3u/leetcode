#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> nums) {
        size_t n = nums.size(), i = 0, j = 1;
        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2; continue;
            }
            if (nums[j] % 2 == 1) {
                j += 2; continue;
            }
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};
