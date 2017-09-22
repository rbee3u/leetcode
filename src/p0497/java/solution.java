import java.util.Random;

class Solution {

    private int[][] rects;
    private int[]   areas;
    private int     total;
    private Random  random;

    public Solution(int[][] rects) {
        this.rects = rects;
        areas = new int[rects.length];
        total = 0;
        for (int i = 0; i < rects.length; i++) {
            areas[i] = total;
            total += (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
        }
        random = new Random();
    }

    public int[] pick() {
        int area = random.nextInt(total);
        int upper = 0, lower = areas.length - 1;
        while (upper <= lower) {
            int mid = (upper + lower) / 2;
            if (areas[mid] <= area) {
                upper = mid + 1;
            } else {
                lower = mid - 1;
            }
        }
        area -= areas[lower];
        int dx = rects[lower][2] - rects[lower][0] + 1;
        int dy = rects[lower][3] - rects[lower][1] + 1;
        int x = rects[lower][0] + area % dx;
        int y = rects[lower][1] + area / dx;
        return new int[]{x, y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */