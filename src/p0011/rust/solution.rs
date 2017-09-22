use std::cmp::max;

impl Solution {
    pub fn max_area(hs: Vec<i32>) -> i32 {
        let mut result: usize = 0;
        let mut i: usize = 0;
        let mut j: usize = hs.len();
        while i + 1 < j {
            if hs[i] < hs[j - 1] {
                result = max(result, (j - 1 - i) * hs[i] as usize);
                i += 1;
            } else {
                result = max(result, (j - 1 - i) * hs[j - 1] as usize);
                j -= 1;
            }
        }
        return result as i32;
    }
}
