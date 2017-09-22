#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        unordered_map<int, unordered_map<int, int>> source;
        unordered_map<int, int> row, col, add, sub;
        for (auto &lamp : lamps) {
            auto x = lamp[0], y = lamp[1];
            source[x][y]++, row[x]++, col[y]++, add[x + y]++, sub[x - y]++;
        }
        vector<int> result;
        for (auto &query : queries) {
            auto i = query[0], j = query[1];
            result.push_back(row[i] || col[j] || add[i + j] || sub[i - j]);
            for (auto x = i - 1; x <= i + 1; x++) {
                for (auto y = j - 1; y <= j + 1; y++) {
                    if (source[x][y]) {
                        source[x][y]--, row[x]--, col[y]--, add[x + y]--, sub[x - y]--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> lamps = {{0, 0}, {4, 4}};
    vector<vector<int>> queries = {{1, 1}, {1, 0}};
    auto result = sol.gridIllumination(5, lamps, queries);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}