// Merge sort. top-down. 
// O(NlogN). Space O(logN).

class Solution {
public:
    ListNode* merge(ListNode* l, ListNode* r){
        if(l == NULL) return r;
        if(r == NULL) return l;
        if(l->val > r->val){
            r->next = merge(l, r->next);
            return r;
        }
        l->next = merge(l->next, r);
        return l; 
    }
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode *slow, *fast;
        slow = head; fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head); 
        ListNode* right = sortList(fast);
        return merge(left, right);
    }
};
