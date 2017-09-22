class Solution:
    def romanToInt(self, s: str) -> int:
        c2n = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }
        result, prev = 0, 0
        for i in range(len(s), 0, -1):
            curr = c2n[s[i - 1]]
            if curr < prev:
                result -= curr
            else:
                result += curr
            prev = curr
        return result
