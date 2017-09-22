import java.util.Arrays;

class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Arrays.sort(nums);
        int total = 0, value = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num < 0 && k > 0) {
                num = -num; k--;
            }
            total += num;
            value = Math.min(value, num);
        }
        return total - (k % 2) * 2 * value;
    }
}
