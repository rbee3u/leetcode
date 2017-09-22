import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashMap<Integer, Integer> count = new HashMap<>();
        List<String> result = new ArrayList<>();
        for (int i = 0, h = 0; i < s.length(); i++) {
            h = ((h & 0x07ffffff) << 3) | (s.charAt(i) & 7);
            int old = count.getOrDefault(h, 0);
            if (old == 1) {
                result.add(s.substring(i - 9, i + 1));
            }
            count.put(h, old + 1);
        }
        return result;
    }
}
