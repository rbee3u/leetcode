class Solution {
    public int bitwiseComplement(int n) {
        int m = 1 | n | n >> 1;
        m |= m >> 2; m |= m >> 4;
        m |= m >> 8; m |= m >> 16;
        return n ^ m;
    }
}
