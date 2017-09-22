#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    Solution(vector<vector<int>> rects) : rects(rects) {
        total_area = 0;
        for (auto &r : rects) {
            total_area += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            areas.push_back(total_area);
        }
        mt = mt19937(rd());
        dist = uniform_int_distribution<int>(0, total_area - 1);
    }

    vector<int> pick() {
        auto area = dist(mt);
        auto it = upper_bound(areas.begin(), areas.end(), area);
        area -= (it == areas.begin() ? 0 : *(it - 1));
        auto r = rects[it - areas.begin()];
        auto dx = r[2] - r[0] + 1, dy = r[3] - r[1] + 1;
        return {r[0] + area % dx, r[1] + area / dx};
    }

private:
    vector<vector<int>> rects;
    vector<int> areas;
    int total_area;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<int> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */
