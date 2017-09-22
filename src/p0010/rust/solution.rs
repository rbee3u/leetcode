impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let (s, p) = (s.as_bytes(), p.as_bytes());
        let matched = &mut vec![false; p.len() + 1];
        for i in 0..=s.len() {
            let mut prev = matched[0];
            matched[0] = i == 0;
            for j in 1..=p.len() {
                let curr = matched[j];
                if p[j - 1] == '*' as u8 {
                    matched[j] = matched[j - 2] || (matched[j] && (p[j - 2] == '.' as u8 || p[j - 2] == s[i - 1]));
                } else {
                    matched[j] = prev && (p[j - 1] == '.' as u8 || p[j - 1] == s[i - 1]);
                }
                prev = curr;
            }
        }
        return matched[p.len()];
    }
}
