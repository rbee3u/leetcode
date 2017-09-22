class Solution:
    def numJewelsInStones(self, j: str, s: str) -> int:
        result = 0
        table = [0] * 256
        for k in j:
            table[ord(k)] = 1
        for k in s:
            result += table[ord(k)]
        return result
