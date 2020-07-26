// I use lca to calculate all leaf distance. straight.
// the val doesn't matter.
// O(NlogN).
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
    int tre[1200][12] = {};
    vector<int> lf;
    int dep[1200] = {};
    int in[1200] = {};
    int out[1200] = {};
    int id = 0, t = 0;
    
    void dfs(TreeNode* root, int p = 0, int d = 0){
        if(!root) return;
        if(!root->left && !root->right) lf.push_back(id);
        dep[id] = d;
        tre[id][0] = p;
        int cur = id++;
        in[cur] = ++t;
        dfs(root->left, cur, d+1);
        dfs(root->right, cur, d+1);
        out[cur] = ++t;
    }
    
    bool anc(int x, int y){
        return in[x] <= in[y] && out[x] >= out[y];
    }
    
    int lca(int x, int y){
        if(anc(x, y)) return x;
        if(anc(y, x)) return y;
        for(int i = 11; i >= 0; --i){
            if(!anc(tre[x][i], y))
                x = tre[x][i];
        }
        return tre[x][0];
    }
    
    int countPairs(TreeNode* root, int distance) {
        memset(tre, 0, sizeof tre);
        int ans = 0;
        dfs(root);
        for(int i = 1; i < 12; ++i){
            for(int k = 0; k < id; ++k){
                tre[k][i] = tre[tre[k][i-1]][i-1];
            }
        }
        for(int i = 0; i < lf.size(); ++i){
            for(int j = i+1; j < lf.size(); ++j){
                int a = lf[i], b = lf[j];
                int p = lca(a, b);
                if((dep[a] + dep[b]) - 2*dep[p] <= distance) ans++;
            }
        }
        return ans;
    }
};

// Solution2, O(N * L * L).
// Very Fast. from bottom up.
// each level cnt left and right. calculate how many is <= distance
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
    int ans = 0, d;
    vector<int> dfs(TreeNode* cur){
        if(!cur) return {};
        if(!cur->left && !cur->right) return {0};
        auto l = dfs(cur->left), r = dfs(cur->right);
        for(int &x: l) ++x;
        for(int &x: r) ++x;
        for(int &a: l)
            for(int &b: r)
                if(a + b <= d) ans++;
        l.insert(l.end(), r.begin(), r.end());
        return l;
    }
    int countPairs(TreeNode* root, int distance) {
        d = distance;
        dfs(root);
        return ans;
    }
};
