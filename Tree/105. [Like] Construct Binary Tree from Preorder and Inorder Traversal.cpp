// O(N). use map to fast search

class Solution {
public:
    unordered_map<int, int> id;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl >= pr || il >= ir) return NULL;
        int val = preorder[pl];
        TreeNode* root = new TreeNode(val);
        int k = id[val];
        int dis = k-il;
        root->left = dfs(preorder, inorder, pl+1, pl+dis+1, il, k); 
        root->right = dfs(preorder, inorder, pl+dis+1, pr, k+1, ir); 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i) id[inorder[i]] = i;
        return dfs(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};

// O(NlogN). just no map.

class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl >= pr) return NULL;
        int val = preorder[pl];
        TreeNode* root = new TreeNode(val);
        int k;
        for(k = il; k < ir && inorder[k] != val; ++k);
        int dis = k-il;
        root->left = dfs(preorder, inorder, pl+1, pl+dis+1, il, k); 
        root->right = dfs(preorder, inorder, pl+dis+1, pr, k+1, ir); 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
