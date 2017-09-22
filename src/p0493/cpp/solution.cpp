class Solution {
public:
    int reversePairs(std::vector<int> &xs) {
        // 首先将所有的 x 和 x * 2 去重。
        std::set<int64_t> uniq;
        for (int64_t x : xs) uniq.insert({x, x * 2});
        // 然后将去重后的数字进行离散映射。
        std::unordered_map<int64_t, int> dict;
        int total = 0, n = 1;
        for (int64_t key : uniq) dict[key] = n++;
        // 从后往前遍历，利用树状数组查询。
        std::vector<int> v(n, 0);
        for (auto i = xs.rbegin(); i != xs.rend(); i++) {
            int64_t t = *i;
            for (int x = dict[t] - 1; x > 0; x -= x & (-x))
                total += v[x];
            for (int y = dict[t * 2]; y < n; y += y & (-y))
                v[y]++;
        }
        return total;
    }
};

class Solution {
public:
    int reversePairs(std::vector<int> &xs) {
        return mergeSort(xs.begin(), xs.end());
    }

private:
    int mergeSort(std::vector<int>::iterator p, std::vector<int>::iterator q) {
        if (std::distance(p, q) <= 1) return 0;
        auto m = p + std::distance(p, q) / 2;
        int count = mergeSort(p, m) + mergeSort(m, q);
        for (auto i = p, j = m; i != m; i++) {
            while (j != q && *i > *j * 2L) j++;
            count += std::distance(m, j);
        }
        std::inplace_merge(p, m, q);
        return count;
    }
};
