class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        int i = 0, j = len-1;
        for (; i < j; ) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            swap(s[i], s[j]); ++i; --j;
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'A'
            || c == 'e' || c == 'E'
            || c == 'i' || c == 'I'
            || c == 'o' || c == 'O'
            || c == 'u' || c == 'U';
    }
};
