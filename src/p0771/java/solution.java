class Solution {
    public int numJewelsInStones(String J, String S) {
        int result = 0;
        int[] dict = new int[256];
        for (int i = 0; i < J.length(); i++) {
            dict[J.charAt(i)] = 1;
        }
        for (int i = 0; i < S.length(); i++) {
            result += dict[S.charAt(i)];
        }
        return result;
    }
}
