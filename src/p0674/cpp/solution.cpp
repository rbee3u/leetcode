#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int result = 0;
        for (int j = -1, i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i - 1] < nums[i]) {
                result = max(result, i - j);
            } else {
                j = i - 1;
            }
        }
        return result;
    }
};
