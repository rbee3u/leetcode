use std::i32::MAX;
use std::i32::MIN;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let s = s.as_bytes();
        let mut y = 0;
        let mut i: usize = 0;
        while i < s.len() && s[i] == ' ' as u8 {
            i += 1;
        }
        if i >= s.len() {
            return y;
        }
        let mut sign = 1;
        if s[i] == '-' as u8 {
            sign = -1;
            i += 1;
        } else if s[i] == '+' as u8 {
            i += 1;
        }
        while i < s.len() && '0' as u8 <= s[i] && s[i] <= '9' as u8 {
            let b = sign * (s[i] as i32 - '0' as i32);
            if sign > 0 && (y > MAX / 10 || (y == MAX / 10 && b > MAX % 10)) {
                y = MAX;
                break;
            }
            if sign < 0 && (y < MIN / 10 || (y == MIN / 10 && b < MIN % 10)) {
                y = MIN;
                break;
            }
            y = y * 10 + b;
            i += 1;
        }

        return y;
    }
}
