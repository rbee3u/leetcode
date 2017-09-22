class Solution {
public:
    string longestPalindrome(const string &s) {
        auto n = 2 * s.length();
        auto asymmetric = [&s, n](size_t center, size_t radius) {
            return center < radius || center + radius > n || (center % 2 != radius % 2
                            && s[(center - radius) / 2] != s[(center + radius) / 2]);
        };
        size_t preCenter = 0, preRadius = 0, maxCenter = 0, maxRadius = 0;
        vector<size_t> p(n, 0);
        for (size_t i = 1; i < n; i++) {
            auto distance = i - preCenter; if (distance <= preRadius) {
                p[i] = min(p[preCenter - distance], preRadius - distance);
            }
            auto curCenter = i, &curRadius = p[i];
            while (!asymmetric(curCenter, curRadius + 1)) {
                curRadius += 1;
            }
            if (preCenter + preRadius < curCenter + curRadius) {
                preCenter = curCenter; preRadius = curRadius;
            }
            if (maxRadius < preRadius) {
                maxCenter = preCenter; maxRadius = preRadius;
            }
        }
        return s.substr((maxCenter - maxRadius) / 2, maxRadius);
    }
};
