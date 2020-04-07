//1. Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = prev;
            prev = tmp;
        }
        
        return prev;   
    }
};

//2. Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;   
    }
};
