class Solution {
public:
    string convert(const string &s, int numRows) {
        if (numRows <= 1) { return s; }
        string result;
        size_t rows = numRows;
        for (size_t k = 0; k < rows; k++) {
            for (size_t x = k; x < s.length();) {
                result.push_back(s[x]);
                x += 2 * (rows - 1);
                if (0 < k && k + 1 < rows) {
                    size_t y = x - k - k;
                    if (y < s.length()) {
                        result.push_back(s[y]);
                    }
                }
            }
        }
        return result;
    }
};
