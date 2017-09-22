class Solution {
public:
    string freqAlphabets(const string &s) {
        string result;
        for (size_t i = 0; i < s.size(); i++) {
            int ord = s[i] - '0';
            if (i + 2 < s.size() && s[i + 2] == '#') {
                ord = ord * 10 + (s[i + 1] - '0');
                i += 2;
            }
            result.push_back('a' + ord - 1);
        }
        return result;
    }
};
