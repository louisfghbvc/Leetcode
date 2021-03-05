// Simple.

class Solution {
public:
    // use bfs to do level order traversal
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        
        vector<double> res;
        while(q.size()){
            double val = 0;
            int cnt = q.size();
            for(int qs = q.size()-1; qs >= 0; --qs){
                TreeNode *cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                val += cur->val;
            }
            res.push_back(val / cnt);
        }
        
        return res;
    }
};
