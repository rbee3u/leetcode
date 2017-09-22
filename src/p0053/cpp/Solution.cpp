class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, sum=0;
        for (auto x : nums) {
            sum += x;
            if (ans < sum) ans = sum;
            if (sum <= 0) sum = 0;
        }
        return ans;
    }
};
