class Solution {
public:
    bool isMatch(const string &s, const string &p) {
        vector<int> match(p.size() + 1, 0);
        for (size_t i = 0; i <= s.size(); i++) {
            auto prev = match[0];
            match[0] = (i == 0);
            for (size_t j = 1; j <= p.size(); j++) {
                auto curr = match[j];
                if (p[j - 1] == '*') {
                    match[j] = match[j - 2] || (match[j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
                } else {
                    match[j] = prev && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                }
                prev = curr;
            }
        }
        return match[p.size()];
    }
};
