#include <iostream>
#include <vector>
#include <random>

using namespace std;


class Solution {
public:
    Solution(vector<int> nums) : nums(nums) {
        mt = mt19937(rd());
    }

    int pick(int target) {
        int result = -1;
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            n++;
            if (dist(mt) % n == 0) {
                result = i;
            }
        }
        return result;
    }

private:
    vector<int> nums;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */