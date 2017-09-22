class Solution {
    public int countPrimeSetBits(int L, int R) {
        int result = 0;
        for (int x = L; x <= R; x++) {
            int n = x;
            n -= n >> 1 & 0x55555555;
            n = (n & 0x33333333) + (n >> 2 & 0x33333333);
            n = n + (n >> 4) & 0x0f0f0f0f;
            n = n * 0x01010101 >> 24;
            if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11
                    || n == 13 || n == 17 || n == 19) result++;
        }
        return result;
    }
}
