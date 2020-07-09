// O(N). BFS
// Difficult is the level is very big...
// so we can re-offset each level to a small value.
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
typedef pair<TreeNode*, int> ti;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<ti> q;
        q.push({root, 1});
        int res = 1;
        while(q.size()){
            int size = q.size();
            int l, r;
            int offset = q.front().second;
            for(int i = 0; i < size; ++i){
                auto [node, id] = q.front(); q.pop();
                id -= offset;
                if(i == 0) l = id;
                if(i == size-1) r = id;
                if(node->left) q.push({node->left, id*2});
                if(node->right) q.push({node->right, id*2+1});
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
