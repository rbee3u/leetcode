#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProduct(vector<string> &words) {
        auto n = words.size();
        vector<int> comps(n), sizes(n);
        int result = 0;
        for (int i = 0; i < n; i++) {
            int compi = 0, sizei = int(words[i].size());
            for (auto c : words[i]) {
                compi |= (1 << (c - 'a'));
            }
            comps[i] = compi;
            sizes[i] = sizei;
            for (int j = 0; j < i; j++) {
                if (!(compi & comps[j])) {
                    result = max(result, sizei * sizes[j]);
                }
            }
        }
        return result;
    }
};

