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

// Solution2 bfs
