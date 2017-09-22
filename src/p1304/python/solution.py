class Solution:
    def sumZero(self, n: int) -> List[int]:
        result = [0] * n
        if n % 2 != 0:
            n -= 1
            result[n] = 0
        while n > 0:
            result[n - 1] = n
            result[n - 2] = -n
            n -= 2
        return result
