class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int minSum = 0, minDelta = INT_MAX;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return sum;
                }
                int delta = abs(sum - target);
                if (minDelta > delta) {
                    minSum = sum;
                    minDelta = delta;
                }
            }
        }
        return minSum;
    }
};
