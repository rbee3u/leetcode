class Solution {
    public String intToRoman(int i) {
        return sd[i / 1000] + sc[i % 1000 / 100] + sx[i % 100 / 10] + si[i % 10];
    }

    private static final String[] sd = {"", "M", "MM", "MMM"};
    private static final String[] sc = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    private static final String[] sx = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    private static final String[] si = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
}
