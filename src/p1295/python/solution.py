class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        result = 0
        for x in nums:
            result += (len(str(x)) + 1) % 2
        return result
