// Recursive O(N^2).
class Solution {
public:
    ListNode* insert(ListNode* root, ListNode* cur){
        if(!root){
            return new ListNode(cur->val);
        }
        if(root->val > cur->val){
            ListNode* tmp = new ListNode(cur->val);
            tmp->next = root;
            return tmp;
        }
        root->next = insert(root->next, cur);
        return root;
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* root = NULL;
        while(head){
            root = insert(root, head);
            head = head->next;
        }
        return root;
    }
};

// Iterative. O(N^2)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode* dummy = new ListNode();
        while(cur){
            ListNode* prev = dummy;
            ListNode* nt = prev->next;
            
            while(nt){
                if(cur->val < nt->val) break;
                prev = nt;
                nt = nt->next;
            }
            
            ListNode* tmp = cur->next;
            prev->next = cur;
            cur->next = nt;
            
            cur = tmp;
        }
        return dummy->next;
    }
};
