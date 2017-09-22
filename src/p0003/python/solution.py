class Solution:
    @staticmethod
    def lengthOfLongestSubstring(s: str) -> int:
        count = [0] * 256
        result, i, j = 0, 0, 0
        while j < len(s):
            count[ord(s[j])] += 1
            while count[ord(s[j])] > 1:
                count[ord(s[i])] -= 1
                i += 1
            result = max(result, j + 1 - i)
            j += 1
        return result
