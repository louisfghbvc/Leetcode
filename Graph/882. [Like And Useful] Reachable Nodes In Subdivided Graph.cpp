// Use dijkstra alo to do that. impressive
// O(ElogE). 

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<int>> g(n, vector<int>(n, -1)); // no connect
        for(auto &e: edges){
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
        }
        
        int res = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({maxMoves, 0});
        
        vector<bool> vis(n);
        while(pq.size()){
            auto [move, u] = pq.top(); pq.pop();
            if(vis[u]) continue;
            
            vis[u] = 1;
            res++;
            
            for(int v = 0; v < n; ++v){
                if(g[u][v] >= 0){
                    if(move > g[u][v] && !vis[v]){
                        pq.push({move - 1 - g[u][v], v});
                    }
                    g[v][u] -= min(move, g[u][v]);
                    res += min(move, g[u][v]);
                }
            }
            
        }
        
        return res;
    }
};
