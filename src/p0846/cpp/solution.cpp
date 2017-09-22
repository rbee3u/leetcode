#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int W) {
        map<int, int> dict;
        for (auto k : hand) {
            dict[k]++;
        }
        while (!dict.empty()) {
            auto smallest = dict.begin()->first;
            for (int d = 0; d < W; d++) {
                int key = smallest + d;
                if (!dict.count(key)) return false;
                if (--dict[key] == 0) dict.erase(key);
            }
        }
        return true;
    }
};
