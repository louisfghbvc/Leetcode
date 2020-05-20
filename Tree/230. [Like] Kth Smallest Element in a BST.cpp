// Solution1 O(N), space O(N)
// inorder traversal.
// can optimal to O(k).

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
    vector<int> arr;
    void dfs(TreeNode* root){
        if(!root) return;
        if(root->left) dfs(root->left);
        arr.push_back(root->val);
        if(root->right) dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return arr[k-1];
    }
};

// Solution2 iterative.
// use stack. inorder-traversal.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty()){
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if(--k == 0) return cur->val;
            st.pop();
            cur = cur->right;            
        }
        return -1;
    }
};
