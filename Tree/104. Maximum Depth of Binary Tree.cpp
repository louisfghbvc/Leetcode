// Just bfs. and get depth.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int d = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; ++i){
                TreeNode *cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            d++;
        }
        return d;
    }
};

// O(N). dfs.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};
