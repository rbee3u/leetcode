impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let (mut min_sum, mut min_delta) = (0, std::i32::MAX);
        let mut nums = nums;
        nums.sort();
        for i in 0..nums.len() {
            let (mut j, mut k) = (i + 1, nums.len() - 1);
            while j < k {
                let sum = nums[i] + nums[j] + nums[k];
                if sum < target {
                    j += 1;
                } else if sum > target {
                    k -= 1;
                } else {
                    return sum;
                }
                let delta = i32::abs(sum - target);
                if min_delta > delta {
                    min_sum = sum;
                    min_delta = delta;
                }
            }
        }
        return min_sum;
    }
}
