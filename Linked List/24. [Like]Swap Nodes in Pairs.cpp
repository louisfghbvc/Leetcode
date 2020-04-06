//Method 1, swap pointer
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; 
        ListNode* tmp = head->next;
        head->next = swapPairs(head->next->next);
        tmp->next = head;
        return tmp;
    }
};

//Method 2, swap value
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        int t = head->next->val;
        head->next->val = head->val;
        head->val = t;
        swapPairs(head->next->next);
        return head;
    }
};
