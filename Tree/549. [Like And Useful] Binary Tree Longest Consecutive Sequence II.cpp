// Tree postorder dp, only consider adjacent is fine. O(N)

class Solution {
public:

    int ans;
    // increase, decrease
    array<int, 2> dfs(TreeNode* root){
        if(!root) return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        array<int, 2> res = {1, 1};
        if(root->left){
            // decrease path
            if(root->left->val == root->val+1){
                res[1] = max(res[1], left[1]+1);
            }
            if(root->left->val == root->val-1){
                res[0] = max(res[0], left[0]+1);
            }
        }
        if(root->right){
            if(root->right->val == root->val+1){
                res[1] = max(res[1], right[1]+1);
            }
            if(root->right->val == root->val-1){
                res[0] = max(res[0], right[0]+1);
            }
        }
        ans = max(res[0] + res[1] - 1, ans);
        return res;
    }
    
    int longestConsecutive(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
