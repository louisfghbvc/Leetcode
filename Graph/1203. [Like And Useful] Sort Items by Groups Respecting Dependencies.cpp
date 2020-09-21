// Very Tricky. Wrap node to 1 graph. and then dfs. from big to small. 
// because indegree big also is small but the relative order will not change.
// O(N+2*M).
class Solution {
public:
    bool dfs(vector<unordered_set<int>> &g, vector<int> &vis, vector<int> &res, int u){
        if(vis[u]) return vis[u] == 2;
        vis[u] = 1;
        for(int v: g[u]){
            if(!dfs(g, vis, res, v)) return false;
        }
        vis[u] = 2;
        res.push_back(u);
        return true;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<unordered_set<int>> g(n+2*m);
        vector<int> vis(n+2*m);
        for(int i = 0; i < n; ++i){
            if(group[i] != -1){
                g[group[i]+n].insert(i);
                g[i].insert(n+m+group[i]);
            }
            for(int j : beforeItems[i]){
                if(group[i] != -1 && group[i] == group[j]) g[j].insert(i);
                else{
                    int ig = group[i] == -1 ? i : n+group[i];
                    int jg = group[j] == -1 ? j : m+n+group[j];
                    g[jg].insert(ig);
                }
            }
        }
        
        vector<int> res, ans(n);
        for(int u = g.size()-1; u >= 0; --u)
            if(!dfs(g, vis, res, u)) return {};
        reverse(res.begin(), res.end());
        copy_if(res.begin(), res.end(), ans.begin(), [&](int i){ return i < n;});
        return ans;
    }
};
