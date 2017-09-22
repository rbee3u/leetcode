class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;
        int[] comps = new int[n];
        int[] sizes = new int[n];
        int result = 0;
        for (int i = 0; i < n; i++) {
            int compi = 0, sizei = words[i].length();
            for (int k = 0; k < sizei; k++) {
                compi |= 1 << (words[i].charAt(k) - 'a');
            }
            comps[i] = compi;
            sizes[i] = sizei;
            for (int j = 0; j < i; j++) {
                if ((compi & comps[j]) == 0) {
                    result = Math.max(result, sizei * sizes[j]);
                }
            }
        }
        return result;
    }
}
