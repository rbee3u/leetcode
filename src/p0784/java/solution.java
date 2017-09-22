import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> result = new ArrayList<>();
        dfs(s, "", result);
        return result;
    }
    private void dfs(String s, String t, List<String> result) {
        if (s.length() <= t.length()) {
            result.add(t); return;
        }
        int i = t.length();
        if (Character.isLetter(s.charAt(i))) {
            String lower = t.concat(s.substring(i, i + 1).toLowerCase());
            dfs(s, lower, result);
            String upper = t.concat(s.substring(i, i + 1).toUpperCase());
            dfs(s, upper, result);
        } else {
            String other = t.concat(s.substring(i, i + 1));
            dfs(s, other, result);
        }
    }
}
