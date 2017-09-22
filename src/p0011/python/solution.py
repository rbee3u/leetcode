class Solution:
    def maxArea(self, hs: List[int]) -> int:
        result, i, j = 0, 0, len(hs)
        while i + 1 < j:
            if hs[i] < hs[j - 1]:
                result, i = max(result, (j - 1 - i) * hs[i]), i + 1
            else:
                result, j = max(result, (j - 1 - i) * hs[j - 1]), j - 1
        return result
