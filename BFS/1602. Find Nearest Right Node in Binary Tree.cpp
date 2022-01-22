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

// simple O(N), O(H)

class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        // bfs
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            // level-order
            bool appear = false;
            for(int qs = q.size()-1; qs >= 0; --qs){
                TreeNode* cur = q.front(); q.pop();
                if(cur == u) appear = true;
                else if(appear) return cur;
                
                // push to next layer
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        
        return NULL;
    }
};
