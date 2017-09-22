impl Solution {
    const N2S: &'static [&'static str] = &["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut result = Vec::new();
        if !digits.is_empty() {
            let s = &mut String::new();
            Self::dfs(digits.as_bytes(), 0, s, &mut result)
        }
        return result;
    }
    fn dfs(digits: &[u8], i: usize, s: &mut String, result: &mut Vec<String>) {
        if i == digits.len() {
            result.push(s.clone());
            return;
        }
        let button = Self::N2S[digits[i] as usize - '0' as usize];
        for x in button.chars() {
            s.push(x);
            Self::dfs(digits, i + 1, s, result);
            s.pop();
        }
    }
}
