impl Solution {
    pub fn longest_common_prefix(v: Vec<String>) -> String {
        let mut result = String::new();
        if v.is_empty() { return result; }
        let mut i: usize = 0;
        loop {
            for j in 0..v.len() {
                if i >= v[j].len() || (v[j].as_bytes()[i] != v[0].as_bytes()[i]) {
                    return result;
                }
            }
            result.push(v[0].as_bytes()[i] as char);
            i += 1;
        }
    }
}
