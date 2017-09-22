class Solution {
public:
    string restoreString(string s, vector<int> &t) {
        for (int i = 0; i < t.size(); i++) {
            while (t[i] != i) {
                swap(s[t[i]], s[i]);
                swap(t[t[i]], t[i]);
            }
        }
        return s;
    }
};
