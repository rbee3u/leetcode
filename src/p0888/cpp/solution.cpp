#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<int> fairCandySwap(vector<int> &xs, vector<int> &ys) {
        int xt = 0; unordered_set<int> xm;
        for (auto x : xs) {
            xt += x; xm.insert(x);
        }
        int yt = 0; for (auto y : ys) yt += y;
        int diff = (yt - xt) / 2;
        for (auto y : ys) {
            if (xm.count(y - diff) > 0) {
                return {y - diff, y};
            }
        }
        return {};
    }
};
