//36ms 24MB
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root){
        if(!head)
            return true;
        if(!root)
            return false;
        if(root->val == head->val)
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        return false;
    }
    bool all(ListNode* head, TreeNode* root){
        if(!root) 
            return false;
        if(dfs(head, root))
            return true;
        return all(head, root->left) || all(head, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return all(head, root);
    }
};

// KMP, convert linked list to array and do kmp to efficient compare
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   vector<int> buildTable(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j && arr[i] != arr[j]) j = res[j-1];
            if (arr[i] == arr[j]) res[i] = ++j;
        }
        return res;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // goal: find out is head is a sub path of a tree
        // idea:
        // we can start from each node
        // try to compare the list node
        // O(n*l)
        // follow up: how to optimized?
        // it's like string compare
        // we can trying to do kmp search in the tree
        // tree => as sequence

        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        auto lps = buildTable(arr);

        auto dfs = [&](auto &self, int i, TreeNode* root) -> bool {
            if (i >= arr.size()) return true;
            if (!root) return false;
            
            // move
            while (i && arr[i] != root->val)
                i = lps[i-1];

            if (arr[i] == root->val) ++i;
            return self(self, i, root->left) || self(self, i, root->right);
        };  

        return dfs(dfs, 0, root);
    }
};
