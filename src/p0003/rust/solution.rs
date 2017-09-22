use std::cmp::max;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let s = s.as_bytes();
        let mut count = vec![0; 256];
        let (mut result, mut i, mut j) = (0, 0, 0);
        while j < s.len() {
            count[s[j] as usize] += 1;
            while count[s[j] as usize] > 1 {
                count[s[i] as usize] -= 1;
                i += 1;
            }
            result = max(result, (j - i + 1) as i32);
            j += 1;
        }
        result
    }
}
