class Solution {
public:
    bool isHappy(int n) {
        for (; ; ) {
            switch (n) {
                case 1: return true;
                case 4: return false;
                default: n = next(n);
            }
        }
    }
private:
    int next(int n) {
        int ret = 0;
        for (int x; n; n /= 10) {
            x = n%10; ret += x*x;
        }
        return ret;
    }
};