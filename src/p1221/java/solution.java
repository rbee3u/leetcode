class Solution {
    public int balancedStringSplit(String s) {
        int result = 0, weight = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'L') {
                weight--;
            } else {
                weight++;
            }
            if (weight == 0) {
                result++;
            }
        }
        return result;
    }
}
