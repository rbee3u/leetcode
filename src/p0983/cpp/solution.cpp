#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        vector<int> dp(DAYS_PER_YEAR + 1, 0);
        for (auto i = 0; i < days.size(); i++) {
            int beg = days[i], end;
            if (i + 1 != days.size()) {
                end = days[i + 1];
            } else {
                end = beg + 1;
            }

            for (int prev, curr = beg; curr < end; curr++) {
                dp[curr] = INT_MAX;
                prev = max(curr - 1, 0);
                if (prev < beg) {
                    dp[curr] = min(dp[curr], dp[prev] + costs[0]);
                } else {
                    dp[curr] = min(dp[curr], dp[prev]);
                }
                prev = max(curr - 7, 0);
                if (prev < beg) {
                    dp[curr] = min(dp[curr], dp[prev] + costs[1]);
                } else {
                    dp[curr] = min(dp[curr], dp[prev]);
                }
                prev = max(curr - 30, 0);
                if (prev < beg) {
                    dp[curr] = min(dp[curr], dp[prev] + costs[2]);
                } else {
                    dp[curr] = min(dp[curr], dp[prev]);
                }
            }
        }
        return dp[days.back()];
    }

private:
    static const int DAYS_PER_YEAR = 365;
};
