from typing import List


class Solution:
    def numPairsDivisibleBy60(self, times: List[int]) -> int:
        result, counts = 0, [0] * 60
        for time in times:
            time %= 60
            result += counts[(60 - time) % 60]
            counts[time] += 1
        return result
