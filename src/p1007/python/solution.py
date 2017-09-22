from typing import List


class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        n = len(A)
        for choose in [A[0], B[0]]:
            i, a, b = 0, 0, 0
            while i < n and (A[i] == choose or B[i] == choose):
                if A[i] != choose: a += 1
                if B[i] != choose: b += 1
                if i + 1 == n: return min(a, b)
                i = i + 1
        return -1
