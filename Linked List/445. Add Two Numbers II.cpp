// O(N). But use extra space. follow up not conquer.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> A, B;
        while(l1){
            A.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            B.push_back(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* root = NULL;
        for(int i = A.size()-1, j = B.size()-1; j >= 0 || i >= 0;){
            int sum = carry + ((i>=0) ? A[i--]: 0) + ((j>=0) ? B[j--]: 0);
            auto head = new ListNode(sum%10);
            head->next = root;
            root = head;
            carry = sum/10;
        }
        if(carry){
            auto head = new ListNode(1);
            head->next = root;
            root = head;
        }
        return root;
    }
};
