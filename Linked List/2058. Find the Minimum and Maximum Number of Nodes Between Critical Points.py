# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        mx_distance, mn_distance = -1, -1
        point = -1 # critical points
        first = -1
        
        i = 0
        while head and head.next and head.next.next:
            # local max, min
            if (head.val < head.next.val > head.next.next.val) or (head.val > head.next.val < head.next.next.val):
                if point != -1:
                    mx_distance = max(mx_distance, i+1 - first)
                    mn_distance = min(mn_distance, i+1 - point) if mn_distance != -1 else i+1 - point
                if first == -1:
                    first = i+1
                point = i+1
            i += 1
            head = head.next
        
        return [mn_distance, mx_distance]
