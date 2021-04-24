class Solution {
public:
    vector<vector<int>> g;
    vector<int> low; // means from child, lowest.
    vector<int> dfn;
    vector<vector<int>> res;
    
    int t;
    void dfs(int u, int p = -1){
        low[u] = dfn[u] = ++t;
        for(int v: g[u]){
            if(p == v) continue; // no need from parent. cuz low
            if(!dfn[v]){
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] > dfn[u]) // u compare smallest from child,  self biggest
                    res.push_back({u, v}); 
            }
            else
                low[u] = min(low[u], dfn[v]);
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        t = 0;
        g = vector<vector<int>>(n);
        low = vector<int>(n);
        dfn = vector<int>(n);
        
        for(auto &e: connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        dfs(0);
        
        return res;
    }
};
