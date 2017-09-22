class Solution {
public:
    static int compress(int x) {
        return x < 2 ? x : (x < 10 ? 2 : (x < 100 ? 3 : 4));
    }

    int getLengthOfOptimalCompression(const string &s, int toRemove) {
        int N = static_cast<int>(s.size()), V = N - toRemove;
        vector<vector<int>> dp(N + 1, vector<int>(V + 1, V));
        dp[0][0] = 0;

        for (int n = 1; n <= N; n++) {
            for (int v = 0; v <= V; v++) {
                for (int m = 1, u = 0; m <= n; m++) {
                    u += (s[n - m] == s[n - 1]);
                    if (v - u < 0 || v - u > n - m) break;
                    dp[n][v] = min(dp[n][v], compress(u) + dp[n - m][v - u]);
                }
                dp[n][v] = min(dp[n][v], dp[n - 1][v]);
            }
        }

        return dp[N][V];
    }
};
