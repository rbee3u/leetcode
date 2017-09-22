class Solution {
    public int myAtoi(String s) {

        int y = 0;
        int i = 0;

        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }
        if (i >= s.length()) {
            return y;
        }

        int sign = 1;
        if (s.charAt(i) == '-') {
            sign = -1;
            i++;
        } else if (s.charAt(i) == '+') {
            i++;
        }

        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int b = sign * (s.charAt(i) - '0');
            if (sign > 0 && (y > Integer.MAX_VALUE / 10 || (y == Integer.MAX_VALUE / 10 && b > Integer.MAX_VALUE % 10))) {
                y = Integer.MAX_VALUE;
                break;
            }
            if (sign < 0 && (y < Integer.MIN_VALUE / 10 || (y == Integer.MIN_VALUE / 10 && b < Integer.MIN_VALUE % 10))) {
                y = Integer.MIN_VALUE;
                break;
            }
            y = y * 10 + b;
            i++;
        }

        return y;
    }
}
