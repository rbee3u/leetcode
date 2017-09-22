class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = 2 * len(s)

        def asymmetric(center, radius):
            return center < radius or center + radius > n or (center % 2 != radius % 2
                            and s[(center - radius) // 2] != s[(center + radius) // 2])

        pre_center, pre_radius, max_center, max_radius = 0, 0, 0, 0
        p = [0] * n
        for i in range(1, n):
            distance = i - pre_center
            if distance <= pre_radius:
                p[i] = min(p[pre_center - distance], pre_radius - distance)
            while not asymmetric(i, p[i] + 1):
                p[i] += 1
            if pre_center + pre_radius < i + p[i]:
                pre_center, pre_radius = i, p[i]
            if max_radius < pre_radius:
                max_center, max_radius = pre_center, pre_radius
        return s[(max_center - max_radius) // 2: (max_center + max_radius) // 2]
