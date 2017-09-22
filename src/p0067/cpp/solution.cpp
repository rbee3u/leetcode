class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.length(), blen=b.length();
        if (alen < blen) {
            a = string(blen-alen, '0') + a;
        } else {
            b = string(alen-blen, '0') + b;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ret = ""; int c = 0;
        for (int i=0; i < a.length(); ++i) {
            int tmp = a[i]-'0' + b[i]-'0' + c;
            ret += tmp % 2 + '0'; c = tmp / 2;
        }
        if (c) ret += '1';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
