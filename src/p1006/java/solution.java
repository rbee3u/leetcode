class Solution {
    public int clumsy(int n) {
        int result = 0;
        for (int sign = 1; n > 0;) {
            int temp = n--;
            if (n > 0) temp *= n--;
            if (n > 0) temp /= n--;
            temp *= sign;
            if (n > 0) temp += n--;
            result += temp;
            sign = -1;
        }
        return result;
    }
}
