class Solution {
private:
    int addTwo(int i1, int i2, int i3, string &num) {
        int sumlen=0, b1=i2-1, b2=i3-1, b3;
        for (int carry=0; b1>=i1 || b2>=i2 || carry; ) {
            (b1 >= i1) && (carry += num[b1--]-'0');
            (b2 >= i2) && (carry += num[b2--]-'0');
            sumlen = sumlen + 1; carry = carry / 10;
        }
        b1 = i2 - 1; b2 = i3 - 1; b3 = b2 + sumlen;
        if (b3 >= num.size()) {
            return -1;
        }
        for (int carry=0; b1>=i1 || b2>=i2 || carry; ) {
            (b1 >= i1) && (carry += num[b1--]-'0');
            (b2 >= i2) && (carry += num[b2--]-'0');
            if (num[b3--]-'0' != carry%10) {
                return -1;
            } carry = carry / 10;
        }
        return (i3 + sumlen);
    }
    bool isValid(int begin, int end, string &num) {
        return (num[begin]!='0' || end-begin==1);
    }
public:
    bool isAdditiveNumber(string &num) {
        int numlen=num.size();
        for (int p=1; p < numlen; ++p) {
            for (int q=p+1; q < numlen; ++q) {
                int i1=0, i2=p, i3=q, i4;
                if (!isValid(i1, i2, num) || !isValid(i2, i3, num)) {
                    continue;
                }
                for (; i3 < numlen; ) {
                    i4 = addTwo(i1, i2, i3, num);
                    if (-1==i4 || !isValid(i3, i4, num)) {
                        break;
                    }
                    i1 = i2; i2 = i3; i3 = i4;
                }
                if (i3 == numlen) {
                    return true;
                }
            }
        }
        return false;
    }
};

