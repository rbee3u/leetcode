impl Solution {
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let (mut result, mut p) = (0, head);
        while let Some(t) = p {
            result = result * 2 + t.val;
            p = t.next;
        }
        return result;
    }
}
