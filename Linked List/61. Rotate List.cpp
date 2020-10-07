// make it circle and connect to head, and find new head, and just go through new head.
// O(N). O(1) space
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        
        ListNode* cur = head;
        int n = 1;
        while(cur->next){
            n++;
            cur = cur->next;
        }
        cur->next = head;
        
        k %= n;
        int id = (n-k)%n;
        for(int i = 0; i < id; ++i) cur = cur->next;
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};
