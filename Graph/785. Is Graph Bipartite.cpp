// A simple 2-color graph problem.
// use vis array to determine if have colored.
// first color choose 1. and dfs every node.
// when node v visited, and check the vis[v] == want color.
// O(N).

class Solution {
public:
    int n;
    vector<int> vis;
    bool dfs(vector<vector<int>>& g, int u, int c = 1){
        if(vis[u]) return vis[u] == c;
        vis[u] = c;
        for(auto &v: g[u]){
            if(!dfs(g, v, 3-c)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) {
        n = g.size();
        vis = vector<int>(n);
        for(int i = 0; i < n; ++i) if(!vis[i] && !dfs(g, i)) return false;
        return true;
    }
};
