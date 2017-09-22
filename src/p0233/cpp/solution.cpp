class Solution {
public:
    typedef long long int LL;
    int countDigitOne(int n) {
        int ret = 0;
        for (LL b = 1, tb; b <= n; b = tb) {
            tb = b * 10;
            ret += n / tb * b;
            int m = n % tb - b + 1;
            m = m > 0 ? m : 0;
            m = m < b ? m : b;
            ret += m;
        }
        return ret;
    }
};
