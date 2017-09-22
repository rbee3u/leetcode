class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        for (; 0==n%4; n/=4);
        if (7==n%8) return 4;
        int i1=1, i2=1, d, t;
        for (d=2; d*d<=n||(d=n)>1; ++d) {
            for (t=0; 0==n%d; n/=d, ++t);
            i1 &= (0==t%2);
            (3==d%4) && (i2 &= (0==t%2));
        }
        return (i1?1:(i2?2:3));
    }
};
