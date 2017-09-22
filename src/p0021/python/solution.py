class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        sentinel = ListNode(0)
        p = sentinel
        while l1 and l2:
            if l1.val < l2.val:
                p.next = l1
                p = p.next
                l1 = l1.next
            else:
                p.next = l2
                p = p.next
                l2 = l2.next
        if l1:
            p.next = l1
        if l2:
            p.next = l2
        return sentinel.next
