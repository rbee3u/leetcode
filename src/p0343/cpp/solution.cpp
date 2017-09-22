class Solution {
public:
    int integerBreak(int n) {
        assert(n >= 2);
        if (n == 2) return 1;
        if (n == 3) return 2;
        int ret = 1, p2, p3;
        switch (n % 3) {
            case 0: p2 = 0; p3 = n/3;
                    break;
            case 1: p2 = 2; p3 = n/3-1;
                    break;
            case 2: p2 = 1; p3 = n/3;
                    break;
            default: "ignore";
        }
        for (; p2--; ) ret *= 2;
        for (; p3--; ) ret *= 3;
        return ret;
    }
};
