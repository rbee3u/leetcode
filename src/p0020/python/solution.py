class Solution:
    def isValid(self, s: str) -> bool:
        def is_match(p, q):
            return p == '(' and q == ')' or \
                   p == '[' and q == ']' or \
                   p == '{' and q == '}'
        stk = []
        for x in s:
            if len(stk) == 0:
                stk.append(x)
            else:
                if is_match(stk[-1], x):
                    stk.pop()
                else:
                    stk.append(x)
        return len(stk) == 0
