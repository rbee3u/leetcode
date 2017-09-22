impl Solution {
    pub fn merge_two_lists(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut l1, mut l2) = (l1, l2);
        let mut sentinel = Box::new(ListNode::new(0));
        let mut p = &mut sentinel;
        while let (Some(t1), Some(t2)) = (l1.as_ref(), l2.as_ref()) {
            if t1.val < t2.val {
                p.next = l1;
                p = p.next.as_mut().unwrap();
                l1 = p.next.take();
            } else {
                p.next = l2;
                p = p.next.as_mut().unwrap();
                l2 = p.next.take();
            }
        }
        if l1.is_some() { p.next = l1; }
        if l2.is_some() { p.next = l2; }
        return sentinel.next;
    }
}
