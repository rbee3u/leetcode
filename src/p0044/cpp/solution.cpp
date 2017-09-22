#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMatch(const string &s, const string &p) {
        auto n = s.size(), m = p.size();
        vector<int> match(m + 1, 0);
        for (auto i = 0; i <= n; i++) {
            auto prev = match[0]; match[0] = (i == 0);
            for (auto j = 1; j <= m; j++) {
                auto curr = match[j];
                if (p[j - 1] == '*') {
                    match[j] = match[j - 1] || match[j];
                } else {
                    match[j] = prev && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
                }
                prev = curr;
            }
        }
        return match[m] != 0;
    }
};
