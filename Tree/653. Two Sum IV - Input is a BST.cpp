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

// use hashset O(N). O(N) clean
class Solution {
public:
    unordered_set<int> st;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(st.count(k - root->val)) return true;
        st.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
