#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int> &costs) {
        int a = 0, b = 0, c;
        for (size_t i = 2; i <= costs.size(); i++) {
            c = min(a + costs[i - 2], b + costs[i - 1]);
            a = b; b = c;
        }
        return b;
    }
};
