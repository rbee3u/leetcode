class Solution {
    public String longestPalindrome(String s) {
        int n = 2 * s.length();
        int preCenter = 0, preRadius = 0, maxCenter = 0, maxRadius = 0;
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            int distance = i - preCenter; if (distance <= preRadius) {
                p[i] = Math.min(p[preCenter - distance], preRadius - distance);
            }
            while (!asymmetric(s, n, i, p[i] + 1)) {
                p[i] += 1;
            }
            if (preCenter + preRadius < i + p[i]) {
                preCenter = i; preRadius = p[i];
            }
            if (maxRadius < preRadius) {
                maxCenter = preCenter; maxRadius = preRadius;
            }
        }
        return s.substring((maxCenter - maxRadius) / 2, (maxCenter + maxRadius) / 2);
    }

    private boolean asymmetric(String s, int n, int center, int radius) {
        return center < radius || center + radius > n || (center % 2 != radius % 2
            && s.charAt((center - radius) / 2) != s.charAt((center + radius) / 2));
    }
}
