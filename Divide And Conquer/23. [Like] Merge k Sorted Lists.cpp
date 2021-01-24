// O(NlogK). think it as merge sort combine.

class Solution {
public:
    ListNode* dfs(vector<ListNode*>& lists, int l, int r){
        if(l > r) return NULL;
        if(l == r) return lists[l];
        int mid = (l+r)/2;
        ListNode* left = dfs(lists, l, mid);
        ListNode* right = dfs(lists, mid+1, r);
        ListNode* res = new ListNode();
        ListNode* cur = res;
        while(left && right){
            if(left->val < right->val){
                cur->next = new ListNode(left->val);
                left = left->next;
            }
            else{
                cur->next = new ListNode(right->val);
                right = right->next;
            }
            cur = cur->next;
        }
        while(left){
            cur->next = new ListNode(left->val);
            left = left->next;
            cur = cur->next;
        }
        while(right){
            cur->next = new ListNode(right->val);
            right = right->next;
            cur = cur->next;
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return dfs(lists, 0, lists.size()-1);
    }
};
