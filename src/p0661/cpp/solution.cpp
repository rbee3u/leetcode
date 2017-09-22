#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        auto n = M.size(), m = M[0].size();
        vector<vector<int>> S(M);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int total = 0, count = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    if (x < 0 || x >= n) continue;
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (y < 0 || y >= m) continue;
                        total += M[x][y]; count++;
                    }
                }
                S[i][j] = total / count;
            }
        }
        return S;
    }
};

