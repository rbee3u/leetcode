class Solution {
public:
    void dfs(vector<string> &equations, size_t i, size_t j,
             int total, vector<bool> &leading, vector<bool> &seen,
             vector<int> &dict, bool &isSolved) {
        while (!isSolved) {
            if (i == equations.size()) {
                isSolved = total == 0;
                return;
            }
            auto expr = equations[i][j];
            if (dict[expr] < 0) {
                for (int k = 0; k < 10; k++) {
                    if (seen[k] || (k == 0 && leading[expr])) {
                        continue;
                    }
                    seen[k] = true;
                    dict[expr] = k;
                    dfs(equations, i, j, total, leading, seen, dict, isSolved);
                    dict[expr] = -1;
                    seen[k] = false;
                }
                return;
            }
            if (j + 1 == equations[i].size()) {
                if (total % 10 != dict[expr]) {
                    return;
                }
                total /= 10;
                i += 1;
                j = 0;
            } else {
                total += dict[expr];
                j += 1;
            }
        }
    }

    bool isSolvable(const vector<string> &words, const string &result) {

        vector<string> equations(result.size());
        vector<bool> leading(256, false);
        if (words.empty() || result.empty()) {
            return false;
        }
        for (auto &word : words) {
            if (words.empty() || word.size() > result.size()) {
                return false;
            }
            leading[word[0]] = true;
            for (auto i = word.size(); i > 0; i--) {
                equations[word.size() - i].push_back(word[i - 1]);
            }
        }
        leading[result[0]] = true;
        for (auto i = result.size(); i > 0; i--) {
            equations[result.size() - i].push_back(result[i - 1]);
        }

        vector<bool> seen(10, false);
        vector<int> dict(256, -1);
        bool isSolved = false;
        dfs(equations, 0, 0, 0, leading, seen, dict, isSolved);
        return isSolved;
    }
};
