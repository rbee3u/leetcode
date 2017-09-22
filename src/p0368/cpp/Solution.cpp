class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(); sort(nums.begin(), nums.end());
        vector<int> dp(n, 1); int maxVal = -1, maxIdx = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i]%nums[j] || dp[i]>dp[j]) continue;
                dp[i] = dp[j] + 1;
            }
            if (maxVal < dp[i]) {maxVal = dp[i]; maxIdx = i;}
        }
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            if (0 == nums[maxIdx]%nums[i]) continue;
            ret.push_back(nums[i]);
        }
        return ret;
    }
};

