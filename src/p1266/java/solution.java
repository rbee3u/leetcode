class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int result = 0;
        for (int i = 1; i < points.length; i++) {
            int dx = points[i][0] - points[i - 1][0];
            int dy = points[i][1] - points[i - 1][1];
            result += Integer.max(Math.abs(dx), Math.abs(dy));
        }
        return result;
    }
}
