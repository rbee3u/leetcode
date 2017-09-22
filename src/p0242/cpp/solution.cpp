class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (auto x : s) {
            ++count[x-'a'];
        }
        for (auto x : t) {
            --count[x-'a'];
        }
        for (auto x : count) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};
