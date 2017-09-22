class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int minSum = 0, minDelta = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1, k = nums.length - 1; j < k; ) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return sum;
                }
                int delta = Math.abs(sum - target);
                if (minDelta > delta) {
                    minSum = sum;
                    minDelta = delta;
                }
            }
        }
        return minSum;
    }
}
