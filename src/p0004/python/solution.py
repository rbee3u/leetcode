class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        total = len(nums1) + len(nums2)
        kth = (total + 1) // 2
        begin = max(kth, len(nums2)) - len(nums2)
        end = min(kth, len(nums1))
        while begin < end:
            i = begin + (end - begin) // 2
            j = kth - i
            if nums1[i] - nums2[j - 1] < 0:
                begin = i + 1
            else:
                end = i
        i = begin
        j = kth - i
        if j == 0:
            left = nums1[i - 1]
        elif i == 0:
            left = nums2[j - 1]
        else:
            left = max(nums1[i - 1], nums2[j - 1])
        if total % 2 != 0:
            return left
        if j == len(nums2):
            right = nums1[i]
        elif i == len(nums1):
            right = nums2[j]
        else:
            right = min(nums1[i], nums2[j])
        return (left + right) / 2
