class Solution:
    @staticmethod
    def twoSum(nums: List[int], target: int) -> List[int]:
        seen = {}

        for j, y in enumerate(nums):
            i = seen.get(target - y)
            if i is not None:
                return [i, j]

            seen[y] = j

        return []
