class Solution {
public:
    int lengthOfLastWord(string s) {
        int slen = s.length();
        int ret = 0, i = slen - 1;
        while (i >= 0 && s[i] == ' ') --i;
        if (i < 0) return false;
        while (i >= 0 && s[i] != ' ') --i, ++ret;
        return ret;
    }
};
