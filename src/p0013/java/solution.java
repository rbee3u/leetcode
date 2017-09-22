class Solution {
    public int romanToInt(String s) {
        int result = 0, prev = 0, curr;
        for (int i = s.length(); i-- > 0; prev = curr) {
            curr = c2n(s.charAt(i));
            if (curr < prev) {
                result -= curr;
            } else {
                result += curr;
            }
        }
        return result;
    }

    private int c2n(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
}
