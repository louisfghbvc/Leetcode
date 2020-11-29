// Simple linked list.
// O(N). just check if a-1th. then next should be list2 head.
// and if bth. list2->next should be list1->next.
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* res = list1;
        int i = 0;
        ListNode* l2h = list2;
        while(list2 && list2->next) list2 = list2->next;
        while(list1){
            ListNode* next = list1->next;
            if(i == a-1) list1->next = l2h;
            if(i == b) list2->next = next;
            list1 = next;
            i++;
        }
        return res;
    }
};
