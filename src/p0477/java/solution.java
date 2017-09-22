class Solution {
    public int totalHammingDistance(int[] nums) {
        int result = 0, ones, n = nums.length;
        for (int i = 0; i < 32; i++) {
            ones = 0;
            for (int num : nums) {
                ones += num >>> i & 1;
            }
            result += ones * (n - ones);
        }
        return result;
    }
}
