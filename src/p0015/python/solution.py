class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        n = len(nums)
        i = 0
        while i + 2 < n:
            if i > 0 and nums[i - 1] == nums[i]:
                i += 1
                continue
            if nums[i] + nums[i + 1] + nums[i + 2] > 0:
                break
            if nums[i] + nums[n - 2] + nums[n - 1] < 0:
                i += 1
                continue
            p, q = i + 1, n - 1
            while p < q:
                sum3 = nums[i] + nums[p] + nums[q]
                if sum3 < 0:
                    p += 1
                elif sum3 > 0:
                    q -= 1
                else:
                    result.append([nums[i], nums[p], nums[q]])
                    p += 1
                    q -= 1
                    while p < q and nums[p - 1] == nums[p]:
                        p += 1
                    while p < q and nums[q] == nums[q + 1]:
                        q -= 1
            i += 1
        return result
