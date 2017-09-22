class Solution {
    public int numPairsDivisibleBy60(int[] times) {
        int result = 0, counts[] = new int[60];
        for (int time : times) {
            time %= 60;
            result += counts[(60 - time) % 60];
            counts[time]++;
        }
        return result;
    }
}
