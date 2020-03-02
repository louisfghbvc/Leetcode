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
