from typing import List


class Solution:
    def longestCommonPrefix(self, v: List[str]) -> str:
        if len(v) == 0:
            return ""
        result, i = "", 0
        while True:
            for j in range(0, len(v)):
                if i >= len(v[j]) or v[j][i] != v[0][i]:
                    return result
            result += v[0][i]
            i = i + 1
