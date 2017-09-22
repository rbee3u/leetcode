use std::cmp::min;

impl Solution {
    pub fn min_insertions(s: String) -> i32 {
        let (s, n) = (s.as_bytes(), s.len());
        let mut dp = vec![0; n + 1];
        for r in 2..=n {
            let i = n - r;
            let mut prev = 0;
            for j in i + 2..=n {
                let temp = dp[j];
                if s[i] == s[j - 1] {
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
}
