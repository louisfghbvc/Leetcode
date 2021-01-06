// O(N). O(1) space. simple 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* cur = dummy->next;
        ListNode* prev = dummy;
        while(cur){
            ListNode* dup = cur->next;
            bool ok = true;
            while(dup && dup->val == cur->val) dup = dup->next, ok = false;
            if(!ok) prev->next = dup; 
            else prev = cur;
            cur = dup;
        }
        
        return dummy->next;
    }
};

// O(N). Clean recursive.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        if(head->val == head->next->val){
            while(head->next && head->val == head->next->val) head = head->next;
            return deleteDuplicates(head->next);
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
