class Solution:
    @staticmethod
    def addTwoNumbers(a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
        sentinel = ListNode(0)
        tail = sentinel
        carry = 0
        while carry or a or b:
            if a:
                carry, a = carry + a.val, a.next
            if b:
                carry, b = carry + b.val, b.next
            tail.next = ListNode(carry % 10)
            tail = tail.next
            carry = carry // 10
        return sentinel.next
