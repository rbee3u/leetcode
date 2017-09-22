class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) return "";
        string ret = "";
        while (1) {
            --n;
            ret = char(n%26+'A') + ret;
            n = n / 26;
            if (n <= 0) break;
        }
        return ret;
    }
};