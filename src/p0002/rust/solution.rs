impl Solution {
    pub fn add_two_numbers(p: Option<Box<ListNode>>, q: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut a, mut b, mut carry) = (p, q, 0);
        let mut sentinel = Box::new(ListNode::new(0));
        let mut tail = &mut sentinel;
        while carry != 0 || a.is_some() || b.is_some() {
            if let Some(t) = a {
                carry += t.val;
                a = t.next;
            }
            if let Some(t) = b {
                carry += t.val;
                b = t.next;
            }
            tail.next = Some(Box::new(ListNode::new(carry % 10)));
            tail = tail.next.as_mut().unwrap();
            carry /= 10;
        }
        sentinel.next
    }
}
