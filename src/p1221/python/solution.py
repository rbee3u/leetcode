class Solution:
    def balancedStringSplit(self, s: str) -> int:
        result, weight = 0, 0
        for x in s:
            if x == 'L':
                weight -= 1
            else:
                weight += 1
            if weight == 0:
                result += 1
        return result
