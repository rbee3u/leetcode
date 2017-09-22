class Solution {
    public int[] singleNumber(int[] nums) {
        int d = 0, x = 0, y = 0;
        for (int e : nums) {
            d ^= e;
        }
        d = d & (-d);
        for (int e : nums) {
            if ((d & e) == 0) {
                x ^= e;
            } else {
                y ^= e;
            }
        }
        return new int[]{x, y};
    }
}
