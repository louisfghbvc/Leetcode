// modify preorder. O(N).

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()){
            TreeNode *cur = st.top(); st.pop();
            res.push_back(cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
