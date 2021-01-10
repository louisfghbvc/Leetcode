// Simple O(N). O(1) space

class Solution {
public:
    
    ListNode* get(ListNode* head, int n){
        for(int i = 0; i < n; ++i) head = head->next;
        return head;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* res = head;
        
        int len = 0;
        for(; head; head = head->next) len++;
        
        ListNode* l = get(res, k-1);
        ListNode* r = get(res, len-k); 
        
        swap(l->val, r->val);
        return res;
    }
};
