#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trusts) {
        vector<int> degree(N + 1, 0);
        for (auto &trust : trusts) {
            degree[trust[0]]--;
            degree[trust[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (degree[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};
