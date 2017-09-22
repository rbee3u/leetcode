impl Solution {
    pub fn next_larger_nodes(head: Option<Box<ListNode>>) -> Vec<i32> {
        let mut result = Vec::new();
        let mut p = head;
        while let Some(t) = p {
            result.push(t.val);
            p = t.next;
        }
        let mut stk: Vec<usize> = Vec::new();
        for i in 0..result.len() {
            while !stk.is_empty() && result[*stk.last().unwrap()] < result[i] {
                result[stk.pop().unwrap()] = result[i];
            }
            stk.push(i);
        }
        while !stk.is_empty() { result[stk.pop().unwrap()] = 0; }
        return result;
    }
}
