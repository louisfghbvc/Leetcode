// my version inspired by inorder traversal stack
// O(N).

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(st.size() || cur){
            while(cur){
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            cur = cur->right;
        }
        
        return res;
    }
};
