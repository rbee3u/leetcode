use std::cmp::max;
use std::cmp::min;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let total = nums1.len() + nums2.len();
        let kth = (total + 1) / 2;
        let mut begin = max(kth, nums2.len()) - nums2.len();
        let mut end = min(kth, nums1.len());
        while begin < end {
            let i = begin + (end - begin) / 2;
            let j = kth - i;
            if nums1[i] < nums2[j - 1] {
                begin = i + 1;
            } else {
                end = i;
            }
        }
        let i = begin;
        let j = kth - i;
        let left = if j == 0 {
            nums1[i - 1]
        } else if i == 0 {
            nums2[j - 1]
        } else {
            max(nums1[i - 1], nums2[j - 1])
        };
        if total % 2 != 0 {
            return left as f64;
        }
        let right = if j == nums2.len() {
            nums1[i]
        } else if i == nums1.len() {
            nums2[j]
        } else {
            min(nums1[i], nums2[j])
        };
        (left as f64 + right as f64) / 2.0
    }
}
