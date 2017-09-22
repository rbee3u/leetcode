class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        if (n % 2 != 0) {
            result[--n] = 0;
        }
        while (n > 0) {
            result[n - 1] = n;
            result[n - 2] = -n;
            n -= 2;
        }
        return result;
    }
}
