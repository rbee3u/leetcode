class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> u(n); u[0]=1;
        int i2=0, i3=0, i5=0;
        for (int i=1; i < n; ++i) {
            int mval=min(u[i2]*2,
            min(u[i3]*3, u[i5]*5));
            u[i] = mval;
            (mval == u[i2]*2) && (++i2);
            (mval == u[i3]*3) && (++i3);
            (mval == u[i5]*5) && (++i5);
        }
        return u[n-1];
    }
};
