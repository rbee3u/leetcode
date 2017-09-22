class Solution {
public:
    static const char *const n2s[];

    vector<string> letterCombinations(const string &digits) {
        vector<string> result;
        if (!digits.empty()) {
            string s;
            dfs(digits, 0, s, result);
        }
        return result;
    }

    static void dfs(const string &digits, size_t i, string &s, vector<string> &result) {
        if (i == digits.size()) {
            result.push_back(s);
            return;
        }
        for (auto p = n2s[digits[i] - '0']; *p != '\0'; p++) {
            s.push_back(*p);
            dfs(digits, i + 1, s, result);
            s.pop_back();
        }
    }
};

const char *const Solution::n2s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
