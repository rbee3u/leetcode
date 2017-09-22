class Solution {
public:
    static int lengthOfLongestSubstring(const string &s) {
        int result = 0;
        vector<int> count(256, 0);

        for (vector<int>::size_type i = 0, j = 0; j < s.length(); j++) {
            for (count[s[j]]++; count[s[j]] > 1; count[s[i]]--, i++);
            result = max(result, static_cast<int>(j - i + 1));
        }

        return result;
    }
};
