// O(N). simple.  
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2){
            int v1 = 0;
            if(l1) v1 = l1->val, l1 = l1->next;
            int v2 = 0;
            if(l2) v2 = l2->val, l2 = l2->next;
            cur->next = new ListNode((v1+v2+carry)%10);
            carry = (v1+v2+carry)/10;
            cur = cur->next;
        }
        if(carry) cur->next = new ListNode(carry);
        return dummy->next;
    }
};
