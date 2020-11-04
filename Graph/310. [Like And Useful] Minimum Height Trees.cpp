// BFS. Topology sort. impressive.
// from degree one into center. when center <= 2, return ans.

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n <= 2){
            for(int i = 0; i < n; ++i) res.push_back(i);
            return res;
        }
        
        vector<int> g[n];
        vector<int> deg(n);
        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        for(int i = 0; i < n; ++i){
            if(deg[i] == 1) res.push_back(i); 
        }
        
        int remain = n; 
        while(remain > 2){
            remain -= res.size();
            vector<int> next;
            for(int u: res){
                for(int v: g[u]){
                    if(--deg[v] == 1) next.push_back(v);
                }
                g[u].clear();
            }
            res = next;
        }
        
        return res;
    }
};


// DFS. longest path. record path. same as diameter.
// clean.
class Solution {
public:
    vector<vector<int>> g;
    vector<int> path;
    int mx, mxp;
    void dfs(int u, int d = 0, int p = -1){
        if(d > mx){
            mx = d;
            mxp = u;
        }
        for(int v: g[u]){
            if(v != p){
                dfs(v, d+1, u);
                path[v] = u;
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>>(n);
        path = vector<int>(n);
        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        mx = 0, mxp = 0;
        path[0] = -1;
        dfs(0);
        
        mx = 0;
        path[mxp] = -1;
        dfs(mxp);
        
        vector<int> res;
        while(mxp != -1){
            res.push_back(mxp);
            mxp = path[mxp];
        }
        
        if(mx & 1) return {res[mx/2], res[mx/2+1]};
        return {res[mx/2]};
    }
};

// DFS. Diameter. dirty. two dfs. and many edge case check.
class Solution {
public:
    vector<vector<int>> g;
    vector<int> dep;
    int mx, mxp;
    void dfs(int u, int d = 0, int p = -1){
        dep[u] = d;
        if(d > mx) mx = d, mxp = u;
        for(int v: g[u]) if(v != p) dfs(v, d+1, u);
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n <= 2){
            vector<int> res;
            for(int i = 0; i < n; ++i) res.push_back(i);
            return res;
        }
        g = vector<vector<int>>(n);
        unordered_set<int> root;
        
        for(auto&e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        mx = 0, mxp = -1;
        dep = vector<int>(n);
        dfs(0);
        for(int i = 0; i < n; ++i) if(dep[i] == mx) root.insert(i);
        
        mx = 0;
        dep = vector<int>(n);
        dfs(mxp);
        for(int i = 0; i < n; ++i) if(dep[i] == mx) root.insert(i);
            
        vector<int> res;
        int mid1 = -1, mid2 = -1;
        int cen = 0;
        if(mx & 1) mid1 = mx/2, mid2 = (mx+1)/2, cen = 2;
        else mid1 = mx/2, cen = 1;
        for(int i = 0; i < n; ++i) if((dep[i] == mid1 || dep[i] == mid2) && !root.count(i)){
            if(cen-- > 0) res.push_back(i);
        }
        return res;
    }
};
