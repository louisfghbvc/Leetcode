// Precompute the 3^5 neightbor and 3^5 * 3^5 neightbor.
// and then dfs + memo. O(N3^M2^M)

class Solution {
public:
    const int mod = 1e9+7;
    int dp[1005][243];
    
    vector<int> g[243];
    bool vis[243];
    
    int n, m;
    int up;
    
    bool check(vector<int> &mm){
        for(int i = 1; i < m; ++i){
            if(mm[i] == mm[i-1]) return false;
        }
        return true;
    }
    bool check(vector<int> &a, vector<int> &b){
        for(int i = 0; i < m; ++i){
            if(a[i] == b[i]) return false;
        }
        return true;
    }
    
    vector<int> cov(int mask){
        vector<int> mm;
        for(int i = 0; i < m; ++i){
            mm.push_back(mask % 3);
            mask /= 3;
        }
        return mm;
    }
    
    
    int dfs(int i, int mask){
        if(i == n-1) return 1;
        if(dp[i][mask] != -1) return dp[i][mask];
        
        long res = 0;
        for(int v: g[mask]){
            res += dfs(i+1, v);
            res %= mod;
        }
        return dp[i][mask] = res;
    }
    
    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof dp);
        this->n = n;
        this->m = m;
        up = pow(3, m);
        
        for(int i = 0; i < up; ++i){
            vector<int> cm = cov(i);
            if(!check(cm)) continue;
            vis[i] = 1;
        }
        
        for(int i = 0; i < up; ++i){
            if(!vis[i]) continue;
            vector<int> cm = cov(i);
            for(int j = 0; j < up; ++j){
                if(!vis[j]) continue;
                vector<int> cj = cov(j);
                if(check(cm, cj)){
                    g[i].push_back(j);
                }
            }
        }
        
        long res = 0;
        for(int i = 0; i < up; ++i){
            if(!vis[i]) continue;
            res += dfs(0, i);
            res %= mod;
        }
        return res;
    }
};
