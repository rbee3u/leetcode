class Solution {
    public String toHex(int num) {
        StringBuilder hex = new StringBuilder();
        for (int s = 28; s >= 0; s -= 4) {
            int b = (num >>> s) & 0xf;
            if (b != 0 || hex.length() > 0 || s == 0) {
                hex.append(map.charAt(b));
            }
        }
        return hex.toString();
    }
    private static final String map = "0123456789abcdef";
}
