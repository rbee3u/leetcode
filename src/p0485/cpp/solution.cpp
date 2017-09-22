#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int result = 0;
        for (int j = -1, i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                j = i; continue;
            }
            result = max(result, i - j);
        }
        return result;
    }
};
