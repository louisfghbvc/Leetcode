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
 
 // recursive art. O(N)
 
class Solution {
public:
    
    TreeNode* dfs(TreeNode* root, bool is_root=true){
        if(!root) return NULL;
        bool is_delete = to_del.count(root->val);
        if(is_root && !is_delete) res.push_back(root);
        root->left = dfs(root->left, is_delete);
        root->right = dfs(root->right, is_delete);
        return is_delete ? NULL : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return res;
        to_del = unordered_set<int>(to_delete.begin(), to_delete.end());
        dfs(root);
        return res;
    }
    
private:
    unordered_set<int> to_del;
    vector<TreeNode*> res;
};


// Not neat, still can improve to version1 above
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
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode* root, unordered_set<int>& to_delete) {
        if (!root) return nullptr;
        root->left = dfs(root->left, to_delete);
        root->right = dfs(root->right, to_delete);
        if (to_delete.count(root->val)) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return nullptr;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // goal: when we remove a node, the left and right become a root
        // idea:
        // traverse the tree, when meets to_delete -> add left and right
        // how to delete the node in tree?
        // we can make it nullptr
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        dfs(root, st);
        if (!st.count(root->val))
            ans.push_back(root);
        return ans;
    }
};
