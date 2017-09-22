class Solution {
public:
    static const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps / 2 + 1);
        vector<int> dp(arrLen + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < steps; i++) {
            int prev = 0;
            for (int j = 0; j < arrLen; j++) {
                int temp = dp[j];
                dp[j] = (prev + temp) % MODULO;
                dp[j] = (dp[j] + dp[j + 1]) % MODULO;
                prev = temp;
            }
        }
        return dp[0];
    }
};
