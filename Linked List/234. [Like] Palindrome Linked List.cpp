// Reverse half. compare.
// tricky is middle point, slow pass.

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *pre = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        if(fast) slow = slow->next;
        
        while(slow){
            if(slow->val != pre->val) return false;
            slow = slow->next;
            pre = pre->next;
        }
        
        return true;
    }
};
