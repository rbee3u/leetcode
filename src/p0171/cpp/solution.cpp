class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (auto x : s) {
            ret *= 26;
            ret += x-'A'+1;
        }
        return ret;
    }
};