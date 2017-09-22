#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> letterCasePermutation(string &s) {
        vector<string> result;
        dfs(s, "", result);
        return result;
    }

private:
    void dfs(const string &s, const string &t, vector<string> &result) {
        if (s.size() <= t.size()) {
            result.push_back(t); return;
        }
        auto i = t.size();
        if (isalpha(s[i])) {
            string lower(t); lower.push_back(tolower(s[i]));
            dfs(s, lower, result);
            string upper(t); upper.push_back(toupper(s[i]));
            dfs(s, upper, result);
        } else {
            string other(t); other.push_back(s[i]);
            dfs(s, other, result);
        }
    }
};
