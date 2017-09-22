class Solution:
    def reverse(self, x: int) -> int:

        def div10(n):
            return n // 10 if n >= 0 else (n + 9) // 10

        def mod10(n):
            return n - div10(n) * 10

        imin, imax = 0 - 2 ** 31, 2 ** 31 - 1
        y = 0
        while x != 0:
            if x > 0 and (y > div10(imax) or (y == div10(imax) and mod10(x) > mod10(imax))):
                y = 0
                break
            if x < 0 and (y < div10(imin) or (y == div10(imin) and mod10(x) < mod10(imin))):
                y = 0
                break
            y = y * 10 + mod10(x)
            x = div10(x)
        return y
