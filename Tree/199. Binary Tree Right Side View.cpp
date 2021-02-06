// O(N). BFS. level by level
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* last = NULL;
            for(int s = q.size()-1; s >= 0; --s){
                auto tmp = q.front(); q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                last = tmp;
            }
            if(last) res.push_back(last->val);
        }
        return res;
    }
};
