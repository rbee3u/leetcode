class Solution:

    def __init__(self):
        self.n2s = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

    def letterCombinations(self, digits: str) -> List[str]:
        result = []
        if len(digits) > 0:
            self.dfs(digits, 0, "", result)
        return result

    def dfs(self, digits, i, s, result):
        if i == len(digits):
            result.append(s)
            return
        for x in self.n2s[ord(digits[i]) - ord('0')]:
            self.dfs(digits, i + 1, s + x, result)
