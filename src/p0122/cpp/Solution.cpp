class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 0) return 0;
        int imin = prices.front();
        int ans = 0; for (auto x : prices) {
            if (x > imin) { ans += x - imin; }
            imin = x;
        }
        return ans;
    }
};
