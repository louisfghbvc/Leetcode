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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        
        while(head){
            head = head->next;
            
            int sum = 0;
            while(head && head->val){
                sum += head->val;
                head = head->next;
            }
            
            if(sum){
                cur->next = new ListNode(sum);
                cur = cur->next;
            }
            
        }
        
        return dummy->next;
    }
};
