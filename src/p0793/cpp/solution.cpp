class Solution {
public:
    int preimageSizeFZF(int k) {
        int b = 1;
        while (k / b > 4) {
            b = b * 5 + 1;
        }
        while (b > 0) {
            if (k / b > 4) {
                return 0;
            }
            k -= k / b * b;
            b = (b - 1) / 5;
        }
        return 5;
    }
};

