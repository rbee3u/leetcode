#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0, pre = 0; for (auto num : nums) sum += num;
        for (int pivot = 0; pivot < nums.size(); pivot++) {
            if (pre * 2 == sum - nums[pivot]) return pivot;
            pre += nums[pivot];
        }
        return -1;
    }
};
