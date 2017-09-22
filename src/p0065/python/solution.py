class Solution:
    def isNumber(self, s: str) -> bool:

        def isblank(c: str): return c.isspace()
        def isdigit(c: str): return c.isdigit()
        def issign(c: str): return c == '+' or c == '-'
        def isdot(c: str): return c == '.'
        def isexp(c: str): return c == 'e'

        curr = 1
        for c in s:
            if curr == 1:
                if isblank(c): curr = 1; continue
                if  issign(c): curr = 2; continue
                if isdigit(c): curr = 3; continue
                if   isdot(c): curr = 4; continue
                return False
            if curr == 2:
                if isdigit(c): curr = 3; continue
                if   isdot(c): curr = 4; continue
                return False
            if curr == 3:
                if isdigit(c): curr = 3; continue
                if   isdot(c): curr = 5; continue
                if   isexp(c): curr = 6; continue
                if isblank(c): curr = 9; continue
                return False
            if curr == 4:
                if isdigit(c): curr = 5; continue
                return False
            if curr == 5:
                if isdigit(c): curr = 5; continue
                if   isexp(c): curr = 6; continue
                if isblank(c): curr = 9; continue
                return False
            if curr == 6:
                if  issign(c): curr = 7; continue
                if isdigit(c): curr = 8; continue
                return False
            if curr == 7:
                if isdigit(c): curr = 8; continue
                return False
            if curr == 8:
                if isdigit(c): curr = 8; continue
                if isblank(c): curr = 9; continue
                return False
            if curr == 9:
                if isblank(c): curr = 9; continue
                return False

        return curr == 3 or curr == 5 or curr == 8 or curr == 9
