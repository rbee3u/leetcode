#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isAlienSorted(vector<string>& words, string &order) {
        int trans[26];
        for (auto i = 0; i < order.size(); i++) {
            trans[order[i] - 'a'] = i;
        }
        for (auto j = 0, i = 1; i < words.size(); j++, i++) {
            auto lj = words[j].size(), li = words[i].size();
            bool lessOrEqual = (lj <= li);
            for (auto k = 0; k < lj && k < li; k++) {
                auto diff = trans[words[j][k] - 'a'] - trans[words[i][k] - 'a'];
                if (diff < 0) { lessOrEqual = true; break; }
                if (diff > 0) { lessOrEqual = false; break; }
            }
            if (!lessOrEqual) { return false; }
        }
        return true;
    }
};
