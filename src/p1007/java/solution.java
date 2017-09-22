
class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int n = A.length;
        int i, a, b;
        for (int choose : new int[]{A[0], B[0]}) {
            for (i = a = b = 0; i < n && (A[i] == choose || B[i] == choose); i++) {
                if (A[i] != choose) a++; if (B[i] != choose) b++;
                if (i + 1 == n) return Math.min(a, b);
            }
        }
        return -1;
    }
}
