class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for (int i=2; i <= n; ++i) {
            ret = next(ret);
        }
        return ret;
    }
private:
    string next(string input) {
        string ret = ""; input += '$';
        char c = '^'; int t = 0;
        for (char x : input) {
            if (x != c) {
                ret += fmt(t, c);
                c = x; t = 1;
            } else {
                ++t;
            }
        }
        return ret;
    }
    string fmt(int t, char c) {
        char buff[23] = {'\0'};
        if (t > 0) {
            sprintf(buff, "%d%c", t, c);
        }
        return buff;
    }
};
