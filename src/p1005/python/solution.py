from typing import List
import math


class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort()
        total, value = 0, math.inf
        for num in nums:
            if num < 0 < k:
                num, k = -num, k - 1
            total += num
            value = min(value, num)
        return total - (k % 2) * 2 * value
