impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows <= 1 { return s; }
        let result = &mut Vec::new();
        let s = s.as_bytes();
        let rows = num_rows as usize;
        for k in 0 .. rows {
            let mut x = k;
            while x < s.len() {
                result.push(s[x]);
                x += 2 * (rows - 1);
                if 0 < k && k + 1 < rows {
                    let y = x - k - k;
                    if y < s.len() {
                        result.push(s[y]);
                    }
                }
            }
        }
        String::from_utf8_lossy(result).parse().unwrap()
    }
}
