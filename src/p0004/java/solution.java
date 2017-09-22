class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int total = nums1.length + nums2.length;
        int kth = (total + 1) / 2;
        int begin = Math.max(kth, nums2.length) - nums2.length;
        int end = Math.min(kth, nums1.length);
        while (begin < end) {
            int i = begin + (end - begin) / 2;
            int j = kth - i;
            if (nums1[i] - nums2[j - 1] < 0) {
                begin = i + 1;
            } else {
                end = i;
            }
        }
        int i = begin;
        int j = kth - i;
        double left;
        if (j == 0) {
            left = nums1[i - 1];
        } else if (i == 0) {
            left = nums2[j - 1];
        } else {
            left = Math.max(nums1[i - 1], nums2[j - 1]);
        }
        if (total % 2 != 0) {
            return left;
        }
        double right;
        if (j == nums2.length) {
            right = nums1[i];
        } else if (i == nums1.length) {
            right = nums2[j];
        } else {
            right = Math.min(nums1[i], nums2[j]);
        }
        return (left + right) / 2;
    }
}
