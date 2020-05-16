// Solution1. Optimal, Change origin structure. space O(1)
// odd->next = odd->next->next;
// even->next = even->next->next;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return 0;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; 
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead; 
        return head;
    }
};

// Solution2. space O(N).
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return 0;
        ListNode* tot = head;
        bool dir = 1;
        ListNode* f = NULL;
        ListNode* se = NULL;
        ListNode* sehead = NULL;
        while(tot){
            ListNode* tmp = new ListNode(tot->val);
            if(dir){
                if(!f){
                    f = tmp;
                    head = f;
                }
                else{
                    f->next = tmp;
                    f = f->next;
                }
            }
            else{
                if(!se){
                    se = tmp;
                    sehead = se;
                }
                else{
                    se->next =tmp;
                    se = se->next;
                } 
            }
            dir ^= 1;
            tot = tot->next;
        }
        f->next = sehead;
        return head;
    }
};
