import java.util.HashSet;

class Solution {
    public int subarrayBitwiseORs(int[] nums) {
        HashSet<Integer> result = new HashSet<>();
        HashSet<Integer> prev = new HashSet<>();
        for (int num : nums) {
            prev.add(0);
            HashSet<Integer> curr = new HashSet<>();
            for (int x : prev) {
                curr.add(x | num);
                result.add(x | num);
            }
            prev = curr;
        }
        return result.size();
    }
}
