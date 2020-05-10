// DFS and merge.
// root doesn't add 2 ... shxt.
// if subtree hasApple merge + 2;
// each node merge every child.
// can use one variable instead of visit. because it is tree. no cycle. backedge.
// 332ms. 60.3MB

class Solution {
public:
    vector<vector<int>> g;
    int dfs(int u, int par, vector<bool>& A){
        int res = 0;
        for(int i = 0; i < g[u].size(); ++i){
            int v = g[u][i];
            if(v == par) continue;
            res += dfs(v, u, A);
            if(A[v]) A[u] = 1;   
        }
        if(A[u] && u) return 2 + res; 
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        g.resize(n); 
        for(const auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, hasApple);
    }
};
