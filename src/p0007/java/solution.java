class Solution {
    public int reverse(int x) {
        int y = 0;
        for (; x != 0; x /= 10) {
            if (x > 0 && (y > Integer.MAX_VALUE / 10 || (y == Integer.MAX_VALUE / 10 && x % 10 > Integer.MAX_VALUE % 10))) {
                y = 0;
                break;
            }
            if (x < 0 && (y < Integer.MIN_VALUE / 10 || (y == Integer.MIN_VALUE / 10 && x % 10 < Integer.MIN_VALUE % 10))) {
                y = 0;
                break;
            }
            y = y * 10 + x % 10;
        }
        return y;
    }
}
