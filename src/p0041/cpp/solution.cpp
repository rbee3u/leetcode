class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n=A.size(); for (int i=0; i<n; ++i) {
            while (0<A[i]&&A[i]<=n&&A[A[i]-1]!=A[i]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        int r=1; for (; r<=n && A[r-1]==r; ++r);
        return r;
    }
};
