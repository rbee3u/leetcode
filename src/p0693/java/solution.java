class Solution {
    public boolean hasAlternatingBits(int n) {
        n = (n ^ (n >>> 1)) + 1;
        return (n & -n) == n;
    }
}
