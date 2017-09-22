class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        min_total, min_delta = 0, 2 ** 31 - 1
        nums.sort()
        for i in range(0, len(nums)):
            j, k = i + 1, len(nums) - 1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if total < target:
                    j += 1
                elif total > target:
                    k -= 1
                else:
                    return total
                delta = abs(total - target)
                if min_delta > delta:
                    min_total, min_delta = total, delta
        return min_total
