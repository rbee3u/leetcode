class Solution {
    public int maxArea(int[] hs) {
        int result = 0, i = 0, j = hs.length;
        while (i + 1 < j) {
            if (hs[i] < hs[j - 1]) {
                result = Math.max(result, (j - 1 - i) * hs[i]);
                i++;
            } else {
                result = Math.max(result, (j - 1 - i) * hs[j - 1]);
                j--;
            }
        }
        return result;
    }
}
