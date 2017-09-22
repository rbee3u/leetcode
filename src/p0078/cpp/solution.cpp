#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        auto n = nums.size(), pn = (1UL << n);
        vector<vector<int>> result(pn);
        for (auto pm = 0; pm < pn; pm++) {
            for (auto k = 0; k < n; k++) {
                if ((1 << k) & pm) {
                    result[pm].push_back(nums[k]);
                }
            }
        }
        return result;
    }
};
