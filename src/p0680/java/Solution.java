class Solution {
    public boolean validPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        for (; i < j && s.charAt(i) == s.charAt(j); ++i, --j);
        if (i < j) {
            return validPalindrome(s, i + 1, j)
                || validPalindrome(s, i, j - 1);
        }
        return true;
    }
    private boolean validPalindrome(String s, int i, int j) {
        for (; i < j && s.charAt(i) == s.charAt(j); ++i, --j);
        return i >= j;
    }
}

