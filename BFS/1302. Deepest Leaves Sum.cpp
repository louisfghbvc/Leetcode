// simple bfs.

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        // level order. bfs
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(q.size()){
            int sum = 0;
            for(int i = q.size()-1; i >= 0; --i){
                TreeNode *cur = q.front(); q.pop();
                sum += cur->val;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            res = sum;
        }
        return res;
    }
};
