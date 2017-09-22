class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        for (int i = n - 2; i >= 0; i--) {
            int prev = 0;
            for (int j = i + 2; j <= n; j++) {
                int temp = dp[j];
                if (s.charAt(i) == s.charAt(j - 1)) {
                    // dp[i][j] = dp[i + 1][j - 1]
                    dp[j] = prev;
                } else {
                    // dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1])
                    dp[j] = 1 + Integer.min(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
}
