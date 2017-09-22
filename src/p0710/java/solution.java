import java.util.HashMap;
import java.util.Map;
import java.util.Random;

class Solution {

    private HashMap<Integer, Integer> jump;
    private int total;
    private Random random;

    public Solution(int N, int[] blacklist) {
        jump = new HashMap<>();
        total = N;
        for (int x : blacklist) {
            jump.put(x, -1);
            total--;
        }
        for (int x : blacklist) {
            if (x >= total) continue;
            while (jump.containsKey(N - 1)) N--;
            jump.put(x, --N);
        }
        random = new Random();
    }

    public int pick() {
        int r = random.nextInt(total);
        return jump.getOrDefault(r, r);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */