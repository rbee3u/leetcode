import java.util.Random;

class Solution {

    private double r, x, y;
    private Random random;

    public Solution(double r, double x, double y) {
        this.r = r;
        this.x = x;
        this.y = y;
        random = new Random();
    }

    public double[] randPoint() {
        double theta = random.nextDouble() * 2 * Math.PI;
        double realr = Math.sqrt(random.nextDouble()) * r;
        return new double[]{x + realr * Math.cos(theta), y + realr * Math.sin(theta)};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
