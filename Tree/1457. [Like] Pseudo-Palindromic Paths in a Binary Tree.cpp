// Can do better use bit manipulation.
// use __builtin_popcount() to calculate digit.
// space not optimal. a palindromic just even many times(can ignore even) and odd once.
// O(N).

class Solution {
public:
    int ans;
    bool isP(vector<int> &v){
        int cnt[10] = {};
        for(const auto &x :v) cnt[x]++;
        int f = 0;
        for(int i = 0; i < 10; ++i){
            if(cnt[i] % 2) f++;
        }
        return f <= 1;
    }
    void dfs(TreeNode* root, vector<int> p){
        if(!root) return;
        p.push_back(root->val);
        dfs(root->left, p); 
        dfs(root->right, p); 
        if(!root->left && !root->right && isP(p)) ans++;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        vector<int> t;
        dfs(root, t);
        return ans;
    }
};

// Space Optimal 216ms 106.5MB.
class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int cnt){
        if(!root) return;
        cnt ^= 1<<(root->val-1);
        dfs(root->left, cnt); 
        dfs(root->right, cnt); 
        if(!root->left && !root->right && __builtin_popcount(cnt) <= 1) ans++;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
