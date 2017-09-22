#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        auto total = 0, value = INT_MAX;
        for (auto num : nums) {
            if (num < 0 && k > 0) {
                num = -num; k--;
            }
            total += num;
            value = min(value, num);
        }
        return total - (k % 2) * 2 * value;
    }
};
