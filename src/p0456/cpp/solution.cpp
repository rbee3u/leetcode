#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        auto mid = INT_MIN;
        stack<int> stk;
        for (auto i = nums.size(); i-- > 0;) {
            if (nums[i] < mid) {
                return true;
            }
            while (!stk.empty() && nums[i] > stk.top()) {
                mid = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
