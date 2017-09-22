import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList<>();
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                int n = h << 6 | m;
                n -= n >> 1 & 0x55555555;
                n = (n & 0x33333333) + (n >> 2 & 0x33333333);
                n = n + (n >> 4) & 0x0f0f0f0f;
                n = n + (n >> 8) & 0x00ff00ff;
                if (n == num) {
                    result.add(String.format("%d:%02d", h, m));
                }
            }
        }
        return result;
    }
}
