// Really impressive.
// O(N+M). we want to make two pointer be the same poistion
// A will go a+c+b, B will go b+c+a. after that same.
// so if c == 0, no intersection.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A = headA;
        ListNode *B = headB;
        while(A != B){
            A = !A ? headB : A->next;
            B = !B ? headA : B->next;
        }
        return A;
    }
};
