class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i + 2 < n; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;
            for (int p = i + 1, q = n - 1; p < q; ) {
                int sum3 = nums[i] + nums[p] + nums[q];
                if (sum3 < 0) {
                    p++;
                } else if (sum3 > 0) {
                    q--;
                } else {
                    result.add(Arrays.asList(nums[i], nums[p], nums[q]));
                    p++;
                    q--;
                    while (p < q && nums[p - 1] == nums[p]) p++;
                    while (p < q && nums[q] == nums[q + 1]) q--;
                }
            }
        }
        return result;
    }
}
