class Solution {
public:
    int minInsertions(const string &s) {
        auto n = int(s.length());
        vector<int> dp(n + 1, 0);
        for (auto i = n - 2; i >= 0; i--) {
            int prev = 0;
            for (auto j = i + 2; j <= n; j++) {
                int temp = dp[j];
                if (s[i] == s[j - 1]) {
                    // dp[i][j] = dp[i + 1][j - 1]
                    dp[j] = prev;
                } else {
                    // dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1])
                    dp[j] = 1 + min(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};
