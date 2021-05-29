// O(N).
class Solution {
public:
    TreeNode* ans = NULL;
    // contains p, q
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return {false, false};
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);
        bool conP = (root == p) | left.first | right.first, conQ = (root == q) | left.second | right.second;
        if(conP && conQ){
            if(ans == NULL)
                ans = root;
        }
        return {conP, conQ};
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};

// O(N). Clean ==.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;
    }
};
