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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // goal: reverse the odd level node value
        // idea: bfs
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0; 
        while (q.size()) {
            int ls = q.size();
            vector<int> val;
            vector<TreeNode*> tmp;
            for (int i = 0; i < ls; ++i) {
                TreeNode* cur = q.front(); q.pop();
                val.push_back(cur->val);
                tmp.push_back(cur);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (level & 1) {
                reverse(val.begin(), val.end());
                for (int i = 0; i < ls; ++i) {
                    tmp[i]->val = val[i];
                }
            }
            level++;
        }
        
        return root;
    }
};
