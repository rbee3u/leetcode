from typing import List


class Solution:
    def findJudge(self, n: int, trusts: List[List[int]]) -> int:
        degree = [0] * (n + 1)
        for trust in trusts:
            degree[trust[0]] -= 1
            degree[trust[1]] += 1
        for i in range(1, n + 1):
            if degree[i] == n - 1:
                return i
        return -1
