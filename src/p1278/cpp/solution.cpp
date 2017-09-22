class Solution {
public:
    int palindromePartition(const string &s, int k) {
        auto n = int(s.length());
        vector<vector<int>> mm(n + 1, vector<int>(n + 1));
        for (auto c = 0; c < n * 2; c++) {
            auto d = 0, i = c / 2, j = (c + 1) / 2;
            for (; 0 <= i && j < n; i--, j++)
                mm[i][j + 1] = d += s[i] != s[j];
        }
        vector<int> dp(n + 1, 0x3fffffff); dp[0] = 0;
        for (auto t = 1; t <= k; t++)
            for (auto j = n; j >= 0; j--)
                for (auto i = 0; i < j; i++)
                    dp[j] = min(dp[j], dp[i] + mm[i][j]);
        return dp[n];
    }
};
