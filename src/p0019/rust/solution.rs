impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut sentinel = Box::new(ListNode::new(0));
        sentinel.next = head;
        let mut length = 0;
        let mut p = &sentinel;
        while let Some(ref t) = p.next {
            length += 1;
            p = t;
        }
        let mut p = &mut sentinel;
        for _ in 0..(length - n) {
            p = p.next.as_mut().unwrap();
        }
        let remove_node = p.next.take();
        p.next = remove_node.unwrap().next;
        return sentinel.next;
    }
}
