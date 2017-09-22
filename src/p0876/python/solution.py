class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast, slow = head, head
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
        return slow
