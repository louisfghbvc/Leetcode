// iterative O(N).
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev = NULL;
        int res = INT_MAX;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || st.size()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            if(prev) res = min(res, cur->val - prev->val);
            prev = cur;
            cur = cur->right;
        }
        return res;
    }
};

// Recursive O(N).
class Solution {
public:
    TreeNode *prev;
    int res;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(prev) res = min(res, root->val - prev->val);
        prev = root;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        prev = NULL;
        res = INT_MAX;
        dfs(root);
        return res;
    }
};
