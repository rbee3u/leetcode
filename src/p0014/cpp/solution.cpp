class Solution {
public:
    string longestCommonPrefix(const vector<string> &v) {
        string result;
        if (v.empty()) return result;
        for (size_t i = 0;; i++) {
            for (size_t j = 0; j < v.size(); j++) {
                if (i >= v[j].size() || (v[j][i] != v[0][i])) {
                    return result;
                }
            }
            result.push_back(v[0][i]);
        }
    }
};
