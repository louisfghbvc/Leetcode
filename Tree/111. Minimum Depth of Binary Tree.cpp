// O(N). Faster. just like shortest path. BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 1;
        while(q.size()){
            for(int s = q.size()-1; s >= 0; --s){
                TreeNode* cur = q.front(); q.pop();
                if(!cur->left && !cur->right) return res;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res++;
        }
        return res;
    }
};

// O(N). dfs. bottom-up. cleaner. can not go to null pointer. so that is not leaf.
class Solution {
public:
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return 1+dfs(root->right);
        if(!root->right) return 1+dfs(root->left);
        return 1+min(dfs(root->left), dfs(root->right));
    }
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};
