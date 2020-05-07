// Solution1 dfs, Simple traversal left and right.
// O(N).
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
    pair<int, TreeNode*> dfs(int d, TreeNode* cur, TreeNode* parent, int val){
        if(!cur) return {0, 0};
        if(val == cur->val) return {d, parent};
        pair<int, TreeNode*> l = dfs(d+1, cur->left, cur, val);
        pair<int, TreeNode*> r = dfs(d+1, cur->right, cur, val);
        if(l.second) return l;
        return r;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, TreeNode*> l = dfs(0, root, NULL, x);
        pair<int, TreeNode*> r = dfs(0, root, NULL, y);
        // cout << l.first << " " << l.second << endl;
        // cout << r.first << " " << r.second << endl;
        return l.first == r.first && l.second != r.second;
    }
};

// Solution2 bfs, each node check if child is x and y. same level x and y exist return true
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool x_exist = 0, y_exist = 0;
            for(int i = 0; i < size; ++i){
                TreeNode *cur = q.front(); q.pop();
                if(cur->val == x) x_exist = true;
                if(cur->val == y) y_exist = true;
                if(cur->left && cur->right){
                    if(cur->left->val == x && cur->right->val == y) return 0;
                    if(cur->left->val == y && cur->right->val == x) return 0;
                }
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            if(x_exist && y_exist) return 1;
        }
        return 0;
    }
};
