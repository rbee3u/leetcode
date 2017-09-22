public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        n -= n >> 1 & 0x55555555;
        n = (n >> 2 & 0x33333333) + (n & 0x33333333);
        n = n + (n >> 4) & 0x0f0f0f0f;
        return n * 0x01010101 >>> 24;
    }
}
