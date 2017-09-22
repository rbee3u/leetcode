class Solution {

    class Trie {
        int index;
        long[] pool;
        int root;

        Trie(int[] nums) {
            index = 0;
            pool = new long[nums.length * 31 + 1];
            root = alloc();
            for (int x : nums) {
                int curr = root;
                for (int i = 30; i >= 0; i--) {
                    int key = (x >> i) & 1;
                    int child = getChild(curr, key);
                    if (child == 0) {
                        child = alloc();
                        setChild(curr, key, child);
                    }
                    curr = child;
                }
            }
        }

        private int alloc() {
            return index++;
        }

        private int getChild(int curr, int key) {
            return (int) (pool[curr] >>> (key * 32) & 0xffffffffL);
        }

        private void setChild(int curr, int key, int child) {
            pool[curr] |= ((long) child << (key * 32));
        }

        private int match(int x) {
            int y = 0;
            int curr = root;
            for (int i = 30; i >= 0; i--) {
                int key = (x >> i) & 1;
                int another = key ^ 1;
                if (getChild(curr, another) == 0) {
                    y |= key << i;
                    curr = getChild(curr, key);
                } else {
                    y |= another << i;
                    curr = getChild(curr, another);
                }
            }
            return y;
        }
    }

    public int findMaximumXOR(int[] nums) {
        int result = 0;
        Trie trie = new Trie(nums);
        for (int x : nums) {
            int y = trie.match(x);
            if (result < (x ^ y)) {
                result = (x ^ y);
            }
        }
        return result;
    }
}
