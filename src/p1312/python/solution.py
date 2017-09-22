class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        for i in range(n - 2, -1, -1):
            prev = 0
            for j in range(i + 2, n + 1):
                temp = dp[j]
                if s[i] == s[j - 1]:
                    # dp[i][j] = dp[i + 1][j - 1]
                    dp[j] = prev
                else:
                    # dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1])
                    dp[j] = 1 + min(dp[j], dp[j - 1])
                prev = temp
        return dp[n]
