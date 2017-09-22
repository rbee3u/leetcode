class Solution:
    def myAtoi(self, s: str) -> int:

        y = 0
        i = 0

        while i < len(s) and s[i] == ' ':
            i += 1
        if i >= len(s):
            return y

        sign = 1
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1

        def div10(n):
            return n // 10 if n >= 0 else (n + 9) // 10

        def mod10(n):
            return n - div10(n) * 10

        imin, imax = 0 - 2 ** 31, 2 ** 31 - 1

        while i < len(s) and s[i].isdigit():
            b = sign * (ord(s[i]) - ord('0'))
            if sign > 0 and (y > div10(imax) or (y == div10(imax) and b > mod10(imax))):
                y = imax
                break
            if sign < 0 and (y < div10(imin) or (y == div10(imin) and b < mod10(imin))):
                y = imin
                break
            y = y * 10 + b
            i += 1

        return y
