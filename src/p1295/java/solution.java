class Solution {
    public int findNumbers(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            int length = Integer.toString(nums[i]).length();
            if (length % 2 == 0) result++;
        }
        return result;
    }
}
