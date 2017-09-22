class Solution {
    public String convert(String s, int numRows) {
        if (numRows <= 1) return s;
        StringBuilder result = new StringBuilder();
        for (int k = 0; k < numRows; k++) {
            for (int x = k; x < s.length();) {
                result.append(s.charAt(x));
                x += 2 * (numRows - 1);
                if (0 < k && k < numRows - 1) {
                    int y = x - k - k;
                    if (y < s.length()) {
                        result.append(s.charAt(y));
                    }
                }
            }
        }
        return result.toString();
    }
}
