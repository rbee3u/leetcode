class Solution {
    public int trap(int[] height) {
        int water = 0, lbound = 0, rbound = 0;
        int left = 0, right = height.length;
        while (left < right) {
            if (lbound < rbound) {
                int curr = height[left++];
                lbound = Math.max(lbound, curr);
                water += lbound - curr;
            } else {
                int curr = height[--right];
                rbound = Math.max(rbound, curr);
                water += rbound - curr;
            }
        }
        return water;
    }
}
