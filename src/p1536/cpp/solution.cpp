class Solution {
public:
    int minSwaps(vector<vector<int>> &grid) {
        int n = int(grid.size()); vector<int> f(n, n - 1);
        for (int i = 0; i < n; i++) {
            while (f[i] >= 0 && grid[i][f[i]] < 1) f[i]--;
        }
        int result = 0;
        for (int i = 0, j; i < n; i++) {
            for (j = i; j < n && f[j] > i; j++);
            if (j == n) return -1;
            for (; i < j--; result++) swap(f[j], f[j + 1]);
        }
        return result;
    }
};
