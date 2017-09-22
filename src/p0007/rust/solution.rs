use std::i32::MAX;
use std::i32::MIN;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let (mut x, mut y) = (x, 0);
        while x != 0 {
            if x > 0 && (y > MAX / 10 || (y == MAX / 10 && x % 10 > MAX % 10)) {
                y = 0;
                break;
            }
            if x < 0 && (y < MIN / 10 || (y == MIN / 10 && x % 10 < MIN % 10)) {
                y = 0;
                break;
            }
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
}
