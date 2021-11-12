// Not Optimal, But simple. memory leak maybe. no delete memory

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) head = head->next;
        ListNode* tmp = head;
        while(tmp){
            ListNode* nxt = tmp->next;
            while(nxt && nxt->val == val){
                nxt = nxt->next;
            }
            tmp->next = nxt;
            tmp = tmp->next;
        }
        return head;
    }
};


// recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        if(head->val == val) return removeElements(head->next, val);
        head->next = removeElements(head->next, val);
        return head;
    }
};
