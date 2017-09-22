class Solution {
    public int[] twoSum(int[] nums, int target) {
        var dict = new HashMap<Integer, Integer>();

        for (int j = 0; j < nums.length; j++) {
            var i = dict.get(target - nums[j]);
            if (i != null) {
                return new int[]{i, j};
            }

            dict.put(nums[j], j);
        }

        return new int[]{};
    }
}
