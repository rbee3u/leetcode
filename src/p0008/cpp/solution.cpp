class Solution {
public:
    int myAtoi(string &s) {

        int y = 0;

        size_t i = 0;

        while (i < s.length() && isspace(s[i])) {
            i++;
        }
        if (i >= s.length()) { return y; }

        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            int b = sign * (s[i] - '0');
            if (sign > 0 && (y > INT_MAX / 10 || (y == INT_MAX / 10 && b > INT_MAX % 10))) {
                y = INT_MAX;
                break;
            }
            if (sign < 0 && (y < INT_MIN / 10 || (y == INT_MIN / 10 && b < INT_MIN % 10))) {
                y = INT_MIN;
                break;
            }
            y = y * 10 + b;
            i++;
        }

        return y;
    }
};