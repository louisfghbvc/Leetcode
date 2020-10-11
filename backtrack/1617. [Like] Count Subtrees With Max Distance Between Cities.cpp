// Floyd + Bitmask. 88ms
// O(2^N*N^2).
class Solution {
public:
    int g[20][20];
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        memset(g, 0x3f, sizeof g);
        
        for(auto &e: edges){
            int u = e[0]-1, v = e[1]-1;
            g[u][v] = g[v][u] = 1;
        }
        
        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        
        vector<int> res(n-1);
        for(int k = 1; k < (1<<n); ++k){
            if(__builtin_popcount(k) == 1) continue;
            int d = 0;
            int e = 0;
            for(int i = 0; i < n; ++i){
                if((1<<i)&k){
                    for(int j = i+1; j < n; ++j){
                        if((1<<j)&k){
                            e += g[i][j] == 1;
                            d = max(d, g[i][j]);
                        }
                    }
                }
            }
            if(e == __builtin_popcount(k)-1)
                res[d-1]++;
        }
     
        return res;
    }
};

// O(2^N*N). Tree diameter + bitmask.
// slow because each build graph... ? 216ms.
class Solution {
public:
    int mx, mxp, cnt;
    vector<int> g[17];
    void dfs(int u, int d, int p){
        cnt++;
        if(d > mx){
            mx = d;
            mxp = u;
        }
        for(int v: g[u]){
            if(v != p){
                dfs(v, d+1, u);
            }
        }
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n-1);
        for(int i = 1; i < (1<<n); ++i){
            if(__builtin_popcount(i) == 1) continue;
            for(int j = 0; j <= n; ++j) g[j].clear();
            
            int pt = -1;
            for(auto &e: edges){
                int u = e[0]-1, v = e[1]-1;
                if( ((1<<u)&i) && ((1<<v)&i) ){
                    g[u].emplace_back(v);
                    g[v].emplace_back(u);
                    if(pt == -1) pt = u;
                }
            }
            if(pt == -1) continue;
            
            mx = 0, mxp = -1, cnt = 0;
            dfs(pt, 0, -1);
            mx = 0, cnt = 0;
            dfs(mxp, 0, -1);
            if(cnt == __builtin_popcount(i) && mx > 0){
                res[mx-1]++;
            }
        }
        
        return res;
    }
};
