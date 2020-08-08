// O(N^2), try each node dfs. and sum up. recursive make it simple. clean.
// 24ms
class Solution {
public:
    int dfs(TreeNode* root, int t, int pre){
        if(!root) return 0;
        int cur = pre + root->val;
        return (cur == t) + dfs(root->left, t, cur) + dfs(root->right, t, cur);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return dfs(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};

// BF. use multiset...no san (•_•). can use origin vector.
// Slow. straight forward.
// 1012ms.
class Solution {
public:
    int res;
    void dfs(TreeNode* root, int t, unordered_multiset<int> &s){
        if(!root) return;
        unordered_multiset<int> ns;
        for(auto& x: s){
            if(x + root->val == t) res++;
            ns.insert(x + root->val);
        }
        if(root->val == t) res++;
        ns.insert(root->val);
        dfs(root->left, t, ns);
        dfs(root->right, t, ns);
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_multiset<int> bg;
        dfs(root, sum, bg);
        return res;
    }
};

// O(N). Super smart. prefix map.
// because just like pr - pl = t
// now we change pr - t = pl. same result. and count it.
class Solution {
public:
    int res;
    void dfs(TreeNode* root, int t, int cur, unordered_map<int, int> &mp){
        if(!root) return;
        cur += root->val;
        res += mp[cur-t];
        mp[cur]++;
        dfs(root->left, t, cur, mp);
        dfs(root->right, t, cur, mp);
        mp[cur]--;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        dfs(root, sum, 0, mp);
        return res;
    }
};
