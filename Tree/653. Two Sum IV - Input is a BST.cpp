// Use inorder traversal to into array. then use two pointer like two sum.
// O(N).
class Solution {
public:
    vector<int> arr;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        if(arr.size() < 2) return false;
        int l = 0, r = arr.size()-1;
        while(l < r){
            if(arr[l]+arr[r] == k) return true;
            else if(arr[l]+arr[r] > k) r--;
            else l++;
        }
        return false;
    }
};
