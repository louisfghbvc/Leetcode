// Simple BFS. O(N).

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(q.size()){
            TreeNode* prev = NULL;
            for(int s = q.size()-1; s >= 0; --s){
                TreeNode* cur = q.front(); q.pop();
                if(level % 2 == 0){
                    if((prev && cur->val <= prev->val) || cur->val % 2 == 0){
                        return false;
                    }
                }
                else{
                    if((prev && cur->val >= prev->val) || cur->val % 2 == 1){
                        return false;
                    }
                }
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                prev = cur;
            }
            level++;
        }
        return true;
    }
};
