#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, size_t r, size_t c) {
        auto n = nums.size(), m = nums[0].size();
        if (n * m != r * c) return nums;
        vector<vector<int>> result(r, vector<int>(c, 0));
        size_t i = 0, j = 0;
        for (auto &row : nums) {
            for (auto elem : row) {
                result[i][j] = elem;
                i += (j + 1) / c;
                j =  (j + 1) % c;
            }
        }
        return result;
    }
};
