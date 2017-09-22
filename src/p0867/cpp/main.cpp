#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &A) {
        auto n = A.size(), m = A[0].size();
        vector<vector<int>> B(m, vector<int>(n));
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};
