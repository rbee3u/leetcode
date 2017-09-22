class Solution {
public:
    int reverse(int x) {
        int y = 0;
        for (; x != 0; x /= 10) {
            if (x > 0 && (y > INT_MAX / 10 || (y == INT_MAX / 10 && x % 10 > INT_MAX % 10))) {
                y = 0;
                break;
            }
            if (x < 0 && (y < INT_MIN / 10 || (y == INT_MIN / 10 && x % 10 < INT_MIN % 10))) {
                y = 0;
                break;
            }
            y = y * 10 + x % 10;
        }
        return y;
    }
};
