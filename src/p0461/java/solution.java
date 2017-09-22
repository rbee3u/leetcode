class Solution {
    public int hammingDistance(int x, int y) {
        int n = x ^ y;
        n -= n >> 1 & 0x55555555;
        n = (n & 0x33333333) + (n >> 2 & 0x33333333);
        n = n + (n >> 4) & 0x0f0f0f0f;
        return n * 0x01010101 >> 24;
    }
}
