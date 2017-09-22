class Solution {
    public boolean isMatch(String s, String p) {
        boolean[] match = new boolean[p.length() + 1];
        for (int i = 0; i <= s.length(); i++) {
            boolean prev = match[0];
            match[0] = (i == 0);
            for (int j = 1; j <= p.length(); j++) {
                boolean curr = match[j];
                if (p.charAt(j - 1) == '*') {
                    match[j] = match[j - 2] || (match[j] && (p.charAt(j - 2) == s.charAt(i - 1) || p.charAt(j - 2) == '.'));
                } else {
                    match[j] = prev && (p.charAt(j - 1) == s.charAt(i - 1) || p.charAt(j - 1) == '.');
                }
                prev = curr;
            }
        }
        return match[p.length()];
    }
}
