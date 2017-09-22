class Solution {
public:
    int addDigits(int num) {
        if (num <= 0) {
            return 0;
        } else {
            num %= 9;
            return (num ? num : 9);
        }
    }
};
