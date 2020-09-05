// Simple inorder. and merge 2 sorted array.
// O(N).

class Solution {
public:
    void dfs(vector<int> &bf, TreeNode* root){
        if(!root) return;
        dfs(bf, root->left);
        bf.push_back(root->val);
        dfs(bf, root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        dfs(a, root1);
        dfs(b, root2);
        int i = 0, j = 0;
        vector<int> c;
        while(i < a.size() || j < b.size()){
            if(i == a.size()) c.push_back(b[j++]);
            else if(j == b.size()) c.push_back(a[i++]);
            else{
                if(a[i] > b[j]) c.push_back(b[j++]);
                else c.push_back(a[i++]);
            }
        }
        return c;
    }
};
