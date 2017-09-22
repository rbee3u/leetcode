import collections


class Solution:
    def shortestCompletingWord(self, lp, words):
        cntr_lp, res = collections.defaultdict(int), None
        for char in lp:
            if char.isalpha():
                cntr_lp[char.lower()] += 1
        for word in words:
            check = dict(cntr_lp)
            for char in word:
                char = char.lower()
                if char in check:
                    check[char] -= 1
                    if not check[char]:
                        del check[char]
            if not check and (not res or len(word) < len(res)):
                res = word
        return res
