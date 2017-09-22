#include <iostream>
#include <vector>
#include <cfloat>
#include <algorithm>
#include <cstdint>
#include <unordered_map>

using namespace std;


class Solution {
public:
    double minAreaFreeRect(vector<vector<int>> &points) {
        double result = DBL_MAX;
        unordered_map<int64_t, unordered_map<int64_t, vector<tuple<int, int>>>> dict;
        for (auto i = 0; i < points.size(); i++) {
            for (auto j = 0; j < i; j++) {
                auto c = center(points[i], points[j]);
                auto d = length(points[i], points[j]);
                for (auto [p, q] : dict[c][d]) {
                    result = min(result, area(points[p], points[i], points[j]));
                }
                dict[c][d].push_back({i, j});
            }
        }
        return result == DBL_MAX ? 0 : result;
    }

private:
    int64_t center(const vector<int> &a, const vector<int> &b) const {
        int64_t cx = a[0] + b[0], cy = a[1] + b[1];
        return cx << 32 | cy;
    }
    int64_t length(const vector<int> &a, const vector<int> &b) const {
        int64_t dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
    double area(const vector<int> &p0, const vector<int> &p1, const vector<int> &p2) const {
        return abs((p2[1] - p0[1]) * (p1[0] - p0[0]) - (p1[1] - p0[1]) * (p2[0] - p0[0]));
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{0,2},{0,1},{3,3},{1,0},{2,3},{1,2},{1,3}};
    cout << sol.minAreaFreeRect(points) << endl;
    return 0;
}