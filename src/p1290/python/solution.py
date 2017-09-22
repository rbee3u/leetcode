class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        result, p = 0, head
        while p:
            result, p = result * 2 + p.val, p.next
        return result
