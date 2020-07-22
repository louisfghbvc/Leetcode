// O(N) no need to reverse. use index more concise
// and track from begin or from back
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool left = 1;
        vector<vector<int>> res;
        while(q.size()){
            int s = q.size();
            vector<int> tmp(s);
            for(int i = 0; i < s; i++){
                TreeNode* cur = q.front(); q.pop();
                int id = left ? i: s-1-i;
                tmp[id] = cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res.push_back(tmp);
            left ^= 1;
        }
        return res;
    }
};
