class Solution {
    public int missingNumber(int[] nums) {
        int result = 0, i = 0;
        for (int x : nums) {
            result ^= x ^ (++i);
        }
        return result;
    }
}
