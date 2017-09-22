impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x > 0 && x % 10 == 0 {
            return false;
        }
        let (mut x, mut y) = (x, 0);
        while y < x {
            y = y * 10 + x % 10;
            if x == y { break; }
            x /= 10;
        }
        return x == y;
    }
}
