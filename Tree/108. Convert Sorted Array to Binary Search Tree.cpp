// O(N). pick mid, that must be banlance.

class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid-1);
        root->right = dfs(nums, mid+1, r);  
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};
