// 3 pass O(N).

class Solution {
public:
    vector<vector<int>> g;
    vector<int> size;
    vector<int> dp;
    int n;
    
    void dfs(int u = 0, int p = -1, int dep = 0){ // postorder, count size
        dp[0] += dep;
        for(int v: g[u]) if(v != p){
            dfs(v, u, dep+1);
            size[u] += size[v];
        }
        size[u]++;
    }
    
    void dfs2(int u = 0, int p = -1){ // preorder, calculate ans. math
        for(int v: g[u]) if(v != p) {
            // dp[v] is from dp[u], subtree size distance all -1. and add (n-size[v]).
            dp[v] = dp[u] + n - 2*size[v];
            dfs2(v, u);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n);
        this->n = n;
        g.resize(n);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dp = vector<int>(n);
        size = vector<int>(n);
        dfs();
        dfs2();
        
        return dp;
    }
};
