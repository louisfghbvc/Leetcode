// O(N).

class Solution {
public:
    // new head, new tail
    pair<ListNode*, ListNode*> reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            
            prev = cur;
            cur = next;
        }
        
        return {prev, head};
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--, right--;
        
        ListNode* leftPart = new ListNode();
        ListNode* newHead = leftPart;
        leftPart->next = head;
        
        ListNode* subL = head;
        for(int i = 0; i < left; ++i){
            leftPart = subL;
            subL = subL->next;
        }
        
        ListNode* subR = subL;
        for(int i = left; i < right; ++i) subR = subR->next;
        
        ListNode* rightPart = subR->next;
        subR->next = NULL;
        
        auto reversePart = reverse(subL);
        leftPart->next = reversePart.first;
        reversePart.second->next = rightPart;
        
        return newHead->next;
    }
};

// O(N). Awesome... tricky.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--, right--;
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* tail;
        dummy->next = head;       
        for(int i = 0; i < left; ++i){
            prev = prev->next;
        }
        tail = prev->next;
        
        for(int i = left; i < right; ++i){
            ListNode* tmp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next; // tail next going to begin
            prev->next->next = tmp; // this is awesome
        }
        
        return dummy->next;
    }
};
