// T O(N?). space O(N).

class Solution {
public:
    TreeNode* build(vector<int> &arr, int l, int r){
        if(l > r) return NULL;
        int mid = (l+r) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(arr, l, mid-1);
        root->right = build(arr, mid+1, r);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        for(; head; head = head->next) 
            arr.push_back(head->val);
        return build(arr, 0, arr.size()-1);
    }
};

// O(NlogN). space O(logN). no use vector. use two node

class Solution {
public:
    TreeNode* build(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(head, slow);
        root->right = build(slow->next, tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, NULL);
    }
};
