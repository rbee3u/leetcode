class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        match = [False] * (len(p) + 1)
        for i in range(0, len(s) + 1):
            prev, match[0] = match[0], (i == 0)
            for j in range(1, len(p) + 1):
                if p[j - 1] == '*':
                    prev, match[j] = match[j], match[j - 2] or (match[j] and (p[j - 2] == s[i - 1] or p[j - 2] == '.'))
                else:
                    prev, match[j] = match[j], prev and (p[j - 1] == s[i - 1] or p[j - 1] == '.')
        return match[len(p)]
