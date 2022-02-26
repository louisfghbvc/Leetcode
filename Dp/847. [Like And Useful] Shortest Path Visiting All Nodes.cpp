// BFS, neat and concise.
// O(N^2*2^N)

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // bfs
        // dp[i][bitmask], start from i, visited nodes, shortest path
        int n = graph.size();
        vector<vector<int>> dp(n, vector<int>(1<<n, 1e9));
        
        queue<pair<int, int>> q; // i, mask
        for(int i = 0; i < n; ++i){
            q.push({i, 1<<i});
            dp[i][1<<i] = 0;
        }
        
        while(q.size()){
            for(int qs = q.size()-1; qs >= 0; --qs){
                auto [u, mask] = q.front(); q.pop();
                for(int v: graph[u]){
                    if(dp[v][mask | (1<<v)] > dp[u][mask]+1){
                        dp[v][mask | (1<<v)] = dp[u][mask]+1;
                        q.push({v, mask | (1<<v)});
                    }
                }
            }
        }
        
        int res = 1e9;
        for(int i = 0; i < n; ++i)
            res = min(res, dp[i].back());
        return res;
    }
};

// top down dp + memo
// tricky part is, each v, can let other visit or erase visited by u
// 2 case, need to careful

class Solution {
public:
    // backtracking, for each node, use a bitmask
    // use dp[i][mask], starting from i, visited mask, min path

    int dfs(int u, int mask=0){
        if((mask & (mask-1)) == 0) return 0;
        int &res = dp[u][mask];
        if(res != -1) return res;
        res = 1e9;
        for(int v: g[u]){
            if(mask >> v & 1){
                int visited = dfs(v, mask);
                int not_visited = dfs(v, mask ^ (1<<u));
                res = min(res, 1 + min(not_visited, visited));
            }
        }
        return res;
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        g = graph;
        memset(dp, -1, sizeof dp);
        int res = 1e9;
        for(int i = 0; i < n; ++i)
            res = min(res, dfs(i, (1<<n)-1));
        return res;
    }
    
private:
    vector<vector<int>> g;
    int dp[15][1<<15];
    int n;
};
