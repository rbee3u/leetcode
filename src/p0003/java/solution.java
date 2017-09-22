class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result = 0;
        int[] count = new int[256];

        for (int i = 0, j = 0; j < s.length(); j++) {
            for (count[s.charAt(j)]++; count[s.charAt(j)] > 1; count[s.charAt(i)]--, i++) ;
            result = Math.max(result, j + 1 - i);
        }

        return result;
    }
}
