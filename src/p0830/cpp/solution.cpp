#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<int>> largeGroupPositions(string &s) {
        vector<vector<int>> result;
        char pc = '$'; int pi = -1;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] != pc) {
                if (i - pi >= 3) {
                    result.push_back({pi, i - 1});
                }
                if (i < s.size()) {
                    pc = s[i]; pi = i;
                }
            }
        }
        return result;
    }
};
