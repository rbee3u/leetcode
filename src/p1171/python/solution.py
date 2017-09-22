class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head
        last = {}
        total, p = 0, sentinel
        while p:
            total += p.val
            last[total] = p
            p = p.next
        total, p = 0, sentinel
        while p:
            total += p.val
            p.next = last[total].next
            p = p.next
        return sentinel.next
