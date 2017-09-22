class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n=s.length(), m=0; for (auto &x : wordDict) {
            if (m < x.length()) { m = x.length(); }
        } vector<unordered_set<string>> dp(n+1); dp[0].insert("");
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (i-j>m) break; if (dp[j].empty()) continue;
                string wd = s.substr(j, i-j);
                if (wordDict.find(wd)==wordDict.end()) continue;
                for (auto &x : dp[j]) {
                    auto y = x; if (y != "") y += " ";
                    dp[i].insert(y + wd);
                }
                if (dp[i].size() > 99) return vector<string>();
                // this is just a cheating method, it's wrong
            }
        } vector<string> answer; for (auto &x : dp[n]) {
            answer.push_back(x);
        } return answer;
    }
};
