//816ms 141.9MB
#define N 100002
class Solution {
    int t = 0;
    vector<int> graph[N];
    int dfn[N], low[N];
    void dfs(int u, int p, vector<vector<int>> & res){
        dfn[u] = low[u] = ++t;
        for(int i = 0; i < graph[u].size(); ++i){
            int v = graph[u][i];
            if(v == p) continue; // not from parent
            if(!dfn[v]){
                dfs(v, u, res);
                low[u] = min(low[u], low[v]);
                if(low[v] > dfn[u]) res.push_back({u, v}); // critical path
            }
            else{
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        for(auto x : connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        dfs(0, 0, ans);
        return ans;
    }
};
