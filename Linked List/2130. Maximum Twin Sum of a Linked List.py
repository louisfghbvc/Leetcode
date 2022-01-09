# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        
        # convert to arr
        arr = []
        while head:
            arr.append(head.val)
            head = head.next
        
        mx = 0
        for i in range(len(arr)//2):
            mx = max(arr[i]+arr[len(arr)-1-i], mx)
        return mx
        
        
# can do O(1) space
# reverse the second half linkedlist
# and one-one add
