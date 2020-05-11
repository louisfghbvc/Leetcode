// Solution1. Very Like solution. inorder-traversal. make BST into a ascending order list. => key point.
// now node must greater than inorder node.
// And stack method is pretty cool. try left and pop now, go to right. until.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* inorder = NULL;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(inorder && inorder->val >= root->val) return 0;
            inorder = root;
            root = root->right;
        }
        return 1;
    }
};

// Solution 2. keep lower and upper for each node. limit each node
// Super clean and very useful.
// Divide and Conquer

class Solution {
public:
    bool isBst(TreeNode* root, TreeNode* lower, TreeNode* upper){
        if(!root) return 1;
        if(lower && root->val <= lower->val) return 0;
        if(upper && root->val >= upper->val) return 0;
        return isBst(root->left, lower, root) & isBst(root->right, root, upper);
    }
    bool isValidBST(TreeNode* root) {
        return isBst(root, NULL, NULL);
    }
};
