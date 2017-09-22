class Solution {
public:
    int romanToInt(const string &s) {
        int result = 0, prev = 0, curr;
        for (size_t i = s.size(); i--; prev = curr) {
            curr = c2n(s[i]);
            if (curr < prev) {
                result -= curr;
            } else {
                result += curr;
            }
        }
        return result;
    }

private:
    static int c2n(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};
