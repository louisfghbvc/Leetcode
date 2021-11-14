# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# record the value list
# T: O(N), Space O(N)

class Solution:
    
    def reverseEvenLengthGroups(self, head: Optional[ListNode]) -> Optional[ListNode]: 
        res = head
        i = 0        
        while head:
            move = i+1
            tmp = head
            val = []
            while move and head:
                val += head.val,
                head = head.next
                move -= 1
                
            # even length, reverse only val
            if len(val) % 2 == 0:
                val.reverse()
                move = i+1
                j = 0
                while move and tmp:
                    tmp.val = val[j]
                    tmp = tmp.next
                    move -= 1
                    j += 1
                
            i += 1
        
        return res

# space O(1)      
