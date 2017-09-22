class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        result, stk = [], []
        p = head
        while p:
            result.append(p.val)
            p = p.next
        for i in range(len(result)):
            while len(stk) and result[stk[-1]] < result[i]:
                result[stk.pop()] = result[i]
            stk.append(i)
        while len(stk):
            result[stk.pop()] = 0
        return result
