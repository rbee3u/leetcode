from typing import List
import math


class Solution:
    def commonChars(self, ss: List[str]) -> List[str]:
        curr = [math.inf] * 26
        for s in ss:
            next = [0] * 26
            for c in s:
                if curr[ord(c) - ord('a')] > 0:
                    curr[ord(c) - ord('a')] -= 1
                    next[ord(c) - ord('a')] += 1
            curr = next
        result = []
        for i, v in enumerate(curr):
            for _ in range(v):
                result.append(chr(i + ord('a')))
        return result

