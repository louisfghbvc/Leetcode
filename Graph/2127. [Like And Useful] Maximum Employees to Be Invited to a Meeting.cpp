// use depth to calculate the cycle length.
// use reverse graph to calculate the longest path

class Solution {
public:
    
    // case1, calculate the maximum cycle length
    // case2, calculate all cycle length 2, and longest path to each
    
    vector<int> vis;
    vector<int> depth;
    void dfs(vector<int> &g, int u, int &res, int dep=0){
        vis[u] = 1;
        depth[u] = dep;
        if(vis[g[u]] == 1)
            res = max(res, dep - depth[g[u]] + 1);
        else if(vis[g[u]] == 0)
            dfs(g, g[u], res, dep+1);
        vis[u] = 2;
    }
    
    int longest_path(vector<vector<int>> &g, int u){
        if(depth[u] != -1) return depth[u];
        int res = 0;
        for(int v: g[u])
            res = max(res, longest_path(g, v));
        return depth[u] = 1 + res;
    }
    
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vis = vector<int>(n);
        depth = vector<int>(n);
        
        // case 1
        int cycle_mx = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(favorite, i, cycle_mx);
            }
        }
        
        // case 2
        vector<vector<int>> is_love(n);
        int res = 0;
        for(int i = 0; i < n; ++i)
            is_love[favorite[i]].push_back(i);
        
        depth = vector<int>(n, -1);
        for(int i = 0; i < n; ++i){
            if(depth[i] != -1) continue;
            if(favorite[favorite[i]] == i){
                depth[i] = depth[favorite[i]] = 0;
                int a = 0, b = 0;
                for(int v: is_love[i]){
                    if(v == favorite[i]) continue;
                    a = max(a, longest_path(is_love, v));
                }
                for(int v: is_love[favorite[i]]){
                    if(v == i) continue;
                    b = max(b, longest_path(is_love, v));
                }
                res += a + b + 2;
            }
        }
        
        return max(cycle_mx, res);
    }
};
