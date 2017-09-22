class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(); if (n<=1) return n;
        vector<int> dp(n, 1); int acc = 0;
        for (int i = 1; i < n; ++i) {
            if (ratings[i-1] < ratings[i])
                dp[i] = dp[i-1] + 1;
        }
        for (int i=n-1; i > 0; --i) {
            if (ratings[i-1] > ratings[i])
                dp[i-1] = max(dp[i-1], dp[i]+1);
        }
        for (auto x : dp) acc += x;
        return acc;
    }
};
