import math


class Solution:
    def nearestPalindromic(self, nums: str) -> str:
        numi, size = int(nums), len(nums)
        pivot = (size + 1) // 2
        halfi = int(nums[:pivot])
        result, dist = 0, math.inf
        for x in [-1, 0, 1]:
            halfi2 = halfi + x
            halfs2 = str(halfi2)
            pivot2 = len(halfs2)
            if halfi2 == 0:
                pivot2 = 0
            if pivot2 < pivot:
                numi2 = 10 ** (size - 1) - 1
            elif pivot2 > pivot:
                numi2 = 10 ** size + 1
            else:
                numi2 = int(halfs2 + halfs2[:pivot - size % 2][::-1])
            if numi2 != numi and abs(numi2 - numi) < dist:
                result, dist = str(numi2), abs(numi2 - numi)
        return result


if __name__ == '__main__':
    sol = Solution()
    print(sol.nearestPalindromic('1213'))
