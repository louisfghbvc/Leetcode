// Floyd Cycle Algorithm.
// O(N). Space O(1).

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        do{
            if(slow) slow = slow->next;
            else return NULL;
            if(fast && fast->next) fast = fast->next->next;
            else return NULL;
        }while(slow != fast);
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
