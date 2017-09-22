class Solution {
    private static final double fnan = 1e233;
    private static final double feps = 1e-11;
    public boolean judgePoint24(int[] nums) {
        Arrays.sort(nums); do {
            int a = nums[0], b = nums[1], c = nums[2], d = nums[3], o, p, q;
            for (o = 0; o < 4; ++o) for (p = 0; p < 4; ++p) for (q = 0; q < 4; ++q) {
                if (equal(eval(eval(a, o, b), q, eval(c, p, d)), 24)) return true;
                if (equal(eval(eval(eval(a, o, b), p, c), q, d), 24)) return true;
                if (equal(eval(a, q, eval(b, p, eval(c, o, d))), 24)) return true;
            }
        } while (nextPermutation(nums));
        return false;
    }
    private double eval(double a, int o, double b) {
        double c = fnan; if (!equal(a, fnan) && !equal(b, fnan)) {
            if (o == 0) {c = a + b;} else if (o == 1) {c = a - b;} else
            if (o == 2) {c = a * b;} else if (!equal(b, 0)) {c = a / b;}
        }
        return c;
    }
    private boolean nextPermutation(int[] v) {
        int i = 3; for (; i > 0 && v[i - 1] >= v[i]; --i);
        int j = 3; for (; i > 0 && v[i - 1] >= v[j]; --j);
        if (i > 0) {swap(v, i - 1, j); reverse(v, i, 3);}
        return (i > 0);
    }
    private void swap(int[] v, int i, int j) {
        int k = v[i]; v[i] = v[j]; v[j] = k;
    }
    private void reverse(int[] v, int i, int j) {
        for (; i < j; ++i, --j) swap(v, i, j);
    }
    private boolean equal(double a, double b) {
        return Math.abs(a - b) < feps;
    }
}

