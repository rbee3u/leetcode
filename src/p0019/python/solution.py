class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        sentinel = ListNode(0)
        sentinel.next = head
        first = sentinel
        for _ in range(n):
            first = first.next
        second = sentinel
        while first.next:
            first = first.next
            second = second.next
        remove_node = second.next
        second.next = remove_node.next
        return sentinel.next
