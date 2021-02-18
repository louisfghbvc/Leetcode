// Two Pointer. O(N).

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        ListNode *slow = dummy, *fast = dummy;
        slow->next = head;
        
        for(int i = 0; i <= n; ++i) fast = fast->next;
        
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
