// Recursive but not O(1) space.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode* tmp = head;
        int i;
        for(i = 0; tmp && i < k; i++) tmp = tmp->next;
        
        if(i == k){ // can reverse
            
            // reverse
            ListNode* prev = NULL, *cur = head;
            for(i = 0; i < k; i++){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            
            head->next = reverseKGroup(cur, k);
            return prev;
        }
        
        return head;
    }
};
