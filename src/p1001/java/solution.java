import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public int[] gridIllumination(int N, int[][] lamps, int[][] queries) {
        HashMap<Integer, HashSet<Integer>> sources = new HashMap<>();
        HashMap<Integer, Integer> row = new HashMap<>();
        HashMap<Integer, Integer> col = new HashMap<>();
        HashMap<Integer, Integer> add = new HashMap<>();
        HashMap<Integer, Integer> sub = new HashMap<>();
        for (int[] lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            if (!sources.containsKey(x)) {
                sources.put(x, new HashSet<>());
            }
            sources.get(x).add(y);
            row.put(x, row.getOrDefault(x, 0) + 1);
            col.put(y, col.getOrDefault(y, 0) + 1);
            add.put(x + y, add.getOrDefault(x + y, 0) + 1);
            sub.put(x - y, sub.getOrDefault(x - y, 0) + 1);
        }
        int[] result = new int[queries.length];
        for (int k = 0; k < queries.length; k++) {
            int i = queries[k][0], j = queries[k][1];
            if (row.getOrDefault(i, 0) > 0 ||
                col.getOrDefault(j, 0) > 0 ||
                add.getOrDefault(i + j, 0) > 0 ||
                sub.getOrDefault(i - j, 0) > 0) {
                result[k] = 1;
            }
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (sources.containsKey(x) && sources.get(x).contains(y)) {
                        sources.get(x).remove(y);
                        row.put(x, row.get(x) - 1);
                        col.put(y, col.get(y) - 1);
                        add.put(x + y, add.get(x + y) - 1);
                        sub.put(x - y, sub.get(x - y) - 1);
                    }
                }
            }
        }
        return result;
    }
}
