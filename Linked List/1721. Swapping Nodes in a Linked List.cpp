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

// one pass.
class Solution {
public:
    
    ListNode* swapNodes(ListNode* head, int k) {
        --k;
        ListNode* p1 = head;
        
        for(int i = 0; i < k; ++i) p1 = p1->next;
        
        ListNode* slow = head;
        ListNode* fast = p1->next;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        swap(p1->val, slow->val);
        return head;
    }
};
