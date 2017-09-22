#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string> &strs) {
        vector<int> curr(26, INT_MAX), next(26);
        for (auto &str : strs) {
            fill(next.begin(), next.end(), 0);
            for (auto c : str) {
                if (curr[c - 'a'] > 0) {
                    curr[c - 'a']--;
                    next[c - 'a']++;
                }
            }
            curr.swap(next);
        }
        vector<string> result;
        for (char c = 'a'; c <= 'z'; c++) {
            while (curr[c - 'a']--) {
                result.emplace_back(string(1, c));
            }
        }
        return result;
    }
};
