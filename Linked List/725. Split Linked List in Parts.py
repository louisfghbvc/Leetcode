# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        
        # first, calculate the length
        length = 0
        tmp = head
        while tmp:
            length += 1
            tmp = tmp.next
        
        # second, split to each groups
        remain = length % k
        group_sz = length // k
        res = []
        
        # group id
        i = 1
        while i <= k:
            
            res.append(head)
            
            # add a group
            prev = None
            for j in range(group_sz):
                prev = head
                head = head.next
            
            if i <= remain:
                prev = head
                head = head.next
            
            if prev: prev.next = None
            
            i += 1
            
        return res
        
        
