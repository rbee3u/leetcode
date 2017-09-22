class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_profit = 0;
        for (auto curr_price : prices) {
            min_price = min(min_price, curr_price);
            max_profit = max(max_profit
                        , curr_price - min_price);
        }
        return max_profit;
    }
};
