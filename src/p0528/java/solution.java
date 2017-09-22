import java.util.Random;

class Solution {

    private int[] sum;
    private int total;
    private Random random;

    public Solution(int[] w) {
        sum = w;
        total = sum[0];
        for (int i = 1; i < sum.length; i++) {
            total += sum[i];
            sum[i] += sum[i - 1];
        }
        random = new Random();
    }

    public int pickIndex() {
        int r = random.nextInt(total);
        int upper = 0, lower = sum.length - 1;
        while (upper <= lower) {
            int mid = (upper + lower) / 2;
            if (sum[mid] <= r) {
                upper = mid + 1;
            } else {
                lower = mid - 1;
            }
        }
        return upper;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */