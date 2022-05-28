#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            result += nums[i];
        }
        return result;
    }
};