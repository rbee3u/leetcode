use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut dict = HashMap::new();

        for (j, y) in nums.iter().enumerate() {
            if let Some(i) = dict.get(&(target - *y)) {
                return vec![*i, j as i32];
            }

            dict.insert(*y, j as i32);
        }

        return vec![];
    }
}
