// O(N+M).
// use color to determine the node is in a cycle or not.
// that's say 1 is bad, 2 is good.
// when dfs(u), first, vis[u] = bad.
// and when not visited, dfs(v). and if vis[v] is bad return false. so vis[u] is also bad
// if any node in dfs(v) is bad, return false.
// finally, vis[u] = good, and return true.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> vis(n);
        vector<int> res;
        
        function<bool(int)> dfs; 
        dfs = [&](int u){
            if(vis[u]) return vis[u] == 2;
            vis[u] = 1;
            for(auto &v: g[u]){
                if(vis[v] == 1 || !dfs(v)) return false;
            }
            vis[u] = 2;
            return true;
        };
        
        for(int i = 0; i < n; ++i){
            if(dfs(i)) res.push_back(i);
        }
        
        return res;
    }
};
