class Solution {
public:
    int maxFreq(const string &s, int maxLetters, int minSize, int maxSize) {
        auto n = int(s.length()), d = minSize;
        unordered_map<string, int> frequencies;
        unordered_map<char, int> count;
        for (auto i = 0; i < n; i++) {
            count[s[i]]++;
            if (i + 1 < d) { continue; }
            if (i >= d) {
                if (--count[s[i - d]] == 0) {
                    count.erase(s[i - d]);
                }
            }
            if (count.size() <= maxLetters) {
                frequencies[s.substr(i + 1 - d, d)]++;
            }
        }
        int result = 0;
        for (auto &frequency : frequencies) {
            result = max(result, frequency.second);
        }
        return result;
    }
};
