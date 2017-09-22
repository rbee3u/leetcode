class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n=s.length(), m=0; for (auto &x : wordDict) {
            if (m < x.length()) { m = x.length(); }
        } vector<bool> dp(n + 1); dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (i-j>m) break; if (!dp[j]) continue;
                if (wordDict.find(s.substr(j, i-j))
                    == wordDict.end()) continue;
                dp[i] = true; break;
            }
        }
        return dp[n];
    }
};
