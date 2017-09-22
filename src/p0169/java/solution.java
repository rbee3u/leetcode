class Solution {
    public int majorityElement(int[] nums) {
        int x = 0, n = 0;
        for (int i : nums) {
            if (n == 0 || x == i) {
                x = i;
                n++;
            } else {
                n--;
            }
        }
        return x;
    }
}
