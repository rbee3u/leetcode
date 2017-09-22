class Solution {
    public int getSum(int a, int b) {
        while (b != 0) {
            int t = a & b;
            a ^= b;
            b = t << 1;
        }
        return a;
    }
}
