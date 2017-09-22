import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<String> commonChars(String[] strs) {
        int curr[] = new int[26], next[] = new int[26];
        Arrays.fill(curr, Integer.MAX_VALUE);
        for (String str : strs) {
            Arrays.fill(next, 0);
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (curr[c - 'a'] > 0) {
                    curr[c - 'a']--;
                    next[c - 'a']++;
                }
            }
            int temp[] = curr; curr = next; next = temp;
        }
        List<String> result = new ArrayList<>();
        for (char c = 'a'; c <= 'z'; c++) {
            while (curr[c - 'a']-- > 0) {
                result.add(Character.toString(c));
            }
        }
        return result;
    }
}
