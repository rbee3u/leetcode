impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut sums = vec![0; n];
        let mut sum = 0;
        for i in 0..n {
            sum += nums[i];
            sums[i] = sum;
        }
        return sums;
    }
}
