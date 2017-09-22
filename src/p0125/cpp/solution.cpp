class Solution {
public:
    bool isPalindrome(string s) {
        int slen = s.length();
        int i = 0, j = slen-1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j && !equal(s[i], s[j])) {
                return false;
            }
            ++i; --j;
        }
        return true;
    }
private:
    bool equal(char a, char b) {
        if (isalpha(a) && isalpha(b)) {
            return abs(a-b) == 'a'-'A'
                || a == b;
        } else {
            return a == b;
        }
    }
};
