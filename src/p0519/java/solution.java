import java.util.HashMap;
import java.util.Random;

class Solution {

    private int n_rows, n_cols, total;
    private HashMap<Integer, Integer> dict;
    private Random random;
    public Solution(int n_rows, int n_cols) {
        this.n_rows = n_rows;
        this.n_cols = n_cols;
        total = n_rows * n_cols;
        dict = new HashMap<>();
        random = new Random();
    }

    public int[] flip() {
        int r = random.nextInt(total--);
        int x = dict.getOrDefault(r, r);
        int y = dict.getOrDefault(total, total);
        dict.put(r, y);
        return new int[]{x / n_cols, x % n_cols};
    }

    public void reset() {
        dict = new HashMap<>();
        total = n_rows * n_cols;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
