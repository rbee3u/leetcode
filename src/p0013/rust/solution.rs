impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let s = s.as_bytes();
        let mut result = 0;
        let mut prev = 0;
        let mut curr;
        let mut i = s.len();
        while i > 0 {
            i -= 1;
            curr = Self::c2n(s[i]);
            if curr < prev {
                result -= curr;
            } else {
                result += curr;
            }
            prev = curr;
        }
        return result;
    }

    fn c2n(c: u8) -> i32 {
        match c as char {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0
        }
    }
}
