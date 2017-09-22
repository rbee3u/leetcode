#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &mtx) {
        vector<vector<int>> ans(mtx);
        for (auto &row : ans) {
            reverse(row.begin(), row.end());
            for (auto &elem : row) elem ^= 1;
        }
        return ans;
    }
};
