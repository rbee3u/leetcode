class Solution {
public:
    int climbStairs(int n) {
        assert(n >= 0); int a=1, b=1;
        for (int i=0; i < n; ++i) {
            b = a + b; a = b - a;
        }
        return a;
    }
};
