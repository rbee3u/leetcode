class Solution {
    public int findJudge(int N, int[][] trusts) {
        int[] degree = new int[N + 1];
        for (int[] trust : trusts) {
            degree[trust[0]]--;
            degree[trust[1]]++;
        }
        for (int i = 1; i <= N; i++) {
            if (degree[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
}
