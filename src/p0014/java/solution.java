class Solution {
    public String longestCommonPrefix(String[] v) {
        if (v.length == 0) return "";
        StringBuilder result = new StringBuilder();
        for (int i = 0; ; i++) {
            for (int j = 0; j < v.length; j++) {
                if (i >= v[j].length() || v[j].charAt(i) != v[0].charAt(i)) {
                    return result.toString();
                }
            }
            result.append(v[0].charAt(i));
        }
    }
}
