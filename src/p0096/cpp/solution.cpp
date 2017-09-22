class Solution {
public:
    int numTrees(int n) {
        long long sum = 1;
        for (int i=0; i < n; ++i) {
            sum = sum * (2*n-i) / (i+1);
        }
        return sum / (n + 1);
    }
};
