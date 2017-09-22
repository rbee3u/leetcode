import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length, pn = 1 << n;
        List<List<Integer>> result = new ArrayList<>();
        for (int pm = 0; pm < pn; pm++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int k = 0; k < n; k++) {
                if (((1 << k) & pm) != 0) {
                    temp.add(nums[k]);
                }
            }
            result.add(temp);
        }
        return result;
    }
}
