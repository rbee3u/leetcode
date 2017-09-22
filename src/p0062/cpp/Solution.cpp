class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        long long sum = 1;
        for (int i=0; i < m-1; ++i) {
            sum = sum*(m+n-2-i)/(i+1);
        }
        return sum;
    }
};
