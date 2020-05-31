// Brute-Force bfs. record old path
// Solution1.
class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n+1);
        vector<vector<int>> g(n, vector<int>());
        set<pair<int, int>> st;
        for(const auto&e :connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            st.insert({e[0], e[1]});
        }
        int ans = 0;
        queue<int> q; q.push(0);
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            vis[u] = 1;
            for(const auto& v: g[u]){
                if(vis[v]) continue;
                if(!st.count({u, v})) ans++;
                q.push(v);
            }
        }
        return connections.size()-ans;
    }
};

// Solution2 just reverse path by neg. O(N)
// Calculate postive path parent to child.
class Solution {
public:
    int dfs(vector<vector<int>> &g, vector<bool>& vis, int u){
        int ans = 0;
        vis[u] = 1;
        for(const auto &v: g[u]){
            if(vis[abs(v)]) continue;
            ans += dfs(g, vis, abs(v)) + (v > 0);
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n+1);
        vector<vector<int>> g(n, vector<int>());
        for(const auto&e :connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(-e[0]);
        }
        return dfs(g, vis, 0);
    }
};
