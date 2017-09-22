impl Solution {
    pub fn is_valid(s: String) -> bool {
        let is_match = |p, q| {
            p == '(' && q == ')' ||
            p == '[' && q == ']' ||
            p == '{' && q == '}'
        };
        let mut stk = Vec::new();
        for x in s.chars() {
            if stk.is_empty() {
                stk.push(x)
            } else {
                if is_match(*stk.last().unwrap(), x) {
                    stk.pop();
                } else {
                    stk.push(x);
                }
            }
        }
        return stk.is_empty();
    }
}
