#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int mergeStones(vector<int> &stones, size_t k) {
        size_t n = stones.size();
        size_t m = (n - 1) / (k - 1);
        if ((n - 1) % (k - 1)) return -1;
        vector<int> ps(n + 1, 0);
        for (size_t i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + stones[i];
        }
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));
        for (size_t j = 1; j <= m; j++) {
            size_t r = j * (k - 1);
            for (size_t i = 0; i + r <= n; i++) {
                int cost = INT_MAX;
                for (size_t p = 0)
            }
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<int> stones = {3,2,4,1};
    cout << sol.mergeStones(stones, 2) << endl;
    return 0;
}