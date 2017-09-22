class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (!digits.isEmpty()) {
            dfs(digits, 0, "", result);
        }
        return result;
    }

    static final String[] n2s = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(final String digits, int i, String s, List<String> result) {
        if (i == digits.length()) {
            result.add(s);
            return;
        }
        int n = digits.charAt(i) - '0';
        for (int p = 0; p < n2s[n].length(); p++) {
            dfs(digits, i + 1, s + n2s[n].substring(p, p + 1), result);
        }
    }
}
