// Inorder traversal. use stack. space O(h).
// next() may not be O(1). but space optimal. non recursive.

class BSTIterator {
public:
    stack<TreeNode*> st;
    
    void left(TreeNode* cur){
        for(; cur; cur = cur->left) st.push(cur);
    }
    
    BSTIterator(TreeNode* root) {
        left(root);
    }
    
    int next() {
        TreeNode* tmp = st.top(); st.pop();
        left(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

// O(N). use dfs to record data to array. and both next() and bool hasNext() are O(1).
class BSTIterator {
public:
    vector<int> arr;
    int i = 0;
    
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        return arr[i++];
    }
    
    bool hasNext() {
        return i < arr.size();
    }
};
