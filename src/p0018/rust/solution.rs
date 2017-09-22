impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        let (n, mut result) = (nums.len(), Vec::new());
        nums.sort();
        let mut i = 0;
        while i + 3 < n {
            if i > 0 && nums[i - 1] == nums[i] { i += 1; continue; }
            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target { break; }
            if nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target { i += 1; continue; }
            let mut j = i + 1;
            while j + 2 < n {
                if j > i + 1 && nums[j - 1] == nums[j] { j += 1; continue; }
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target { break; }
                if nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target { j += 1; continue; }
                let sum2 = nums[i] + nums[j];
                let (mut p, mut q) = (j + 1, n - 1);
                while p < q {
                    let sum4 = sum2 + nums[p] + nums[q];
                    if sum4 < target {
                        p += 1;
                    } else if sum4 > target {
                        q -= 1;
                    } else {
                        result.push(vec![nums[i], nums[j], nums[p], nums[q]]);
                        p += 1;
                        q -= 1;
                        while p < q && nums[p - 1] == nums[p] { p += 1; }
                        while p < q && nums[q] == nums[q + 1] { q -= 1; }
                    }
                }
                j += 1
            }
            i += 1
        }
        return result;
    }
}
