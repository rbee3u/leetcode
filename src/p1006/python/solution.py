class Solution:
    def clumsy(self, n: int) -> int:
        result, sign = 0, 1
        while n > 0:
            temp, n = n, n - 1
            if n > 0:
                temp *= n
                n -= 1
            if n > 0:
                temp //= n
                n -= 1
            temp *= sign
            if n > 0:
                temp += n
                n -= 1
            result += temp
            sign = -1
        return result
