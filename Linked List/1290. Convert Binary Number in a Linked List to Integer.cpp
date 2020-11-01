// Simple bit and linkedlist manipulation
// O(N).

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int x = 0;
        while(head){
            x = x * 2 + head->val;
            head = head->next;
        }
        return x;
    }
};
