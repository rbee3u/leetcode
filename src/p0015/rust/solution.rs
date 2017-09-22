impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        let (n, mut result) = (nums.len(), Vec::new());
        nums.sort();
        let mut i = 0;
        while i + 2 < n {
            if i > 0 && nums[i - 1] == nums[i] { i += 1; continue; }
            if nums[i] + nums[i + 1] + nums[i + 2] > 0 { break; }
            if nums[i] + nums[n - 2] + nums[n - 1] < 0 { i += 1; continue; }
            let (mut p, mut q) = (i + 1, n - 1);
            while p < q {
                let sum3 = nums[i] + nums[p] + nums[q];
                if sum3 < 0 {
                    p += 1;
                } else if sum3 > 0 {
                    q -= 1;
                } else {
                    result.push(vec![nums[i], nums[p], nums[q]]);
                    p += 1;
                    q -= 1;
                    while p < q && nums[p - 1] == nums[p] { p += 1; }
                    while p < q && nums[q] == nums[q + 1] { q -= 1; }
                }
            }
            i += 1
        }
        return result;
    }
}
