class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmpMatcher(haystack, needle);
    }
private:
    void computeH(vector<int> &H, string &P) {
        H[0] = -1; int m = P.length();
        for (int q=-1, i=1; i < m; ++i) {
            while (q>=0 && P[q+1]!=P[i]) {q = H[q];}
            if (P[q+1] == P[i]) {q = q + 1;}
            H[i] = q;
        }
    }
    int kmpMatcher(string &T, string &P) {
        int n = T.length(), m = P.length();
        if (m <= 0) return 0;
        vector<int> H(m); computeH(H, P);
        for (int q=-1, i=0; i < n; ++i) {
            while (q>=0 && P[q+1]!=T[i]) {q = H[q];}
            if (P[q+1] == T[i]) {q = q + 1;}
            if (q+1 == m) {return (i-m+1);}
        }
        return -1;
    }
};