class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char f[256] = {'\0'}, g[256] = {'\0'};
        int slen=s.length(), tlen=t.length();
        if (slen != tlen) return false;
        for (int i=0; i < slen; ++i) {
            if (!f[s[i]] && !g[t[i]]) {
                f[s[i]] = t[i];
                g[t[i]] = s[i];
            }
            if (f[s[i]] != t[i]) {
                return false;
            }
            if (g[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
