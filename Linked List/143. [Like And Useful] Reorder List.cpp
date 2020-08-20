// O(N). Use extra space.
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        vector<int> arr;
        auto th = head;
        while(th){
            arr.push_back(th->val);
            th = th->next;
        }
        int n = arr.size();
        for(int l = 0, r = n-1; l < r; ++l, --r){
            head->val = arr[l];
            head = head->next;
            head->val = arr[r];
            head = head->next;
        }
        if(n & 1) head->val = arr[n/2];
    }
};

// No extra.

class Solution {
public:
    ListNode* ReverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur){
            auto tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    void merge(ListNode* p1, ListNode* p2){
        while(p1 && p2){
            ListNode* n1 = p1->next;
            ListNode* n2 = p2->next;
            p1->next = p2;
            p2->next = n1;
            p1 = n1;
            p2 = n2;
        }
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = ReverseList(slow->next);
        ListNode* h2 = slow->next;
        slow->next = NULL;
        merge(head, h2);
    }
};
