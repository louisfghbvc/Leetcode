// Just disjoint Set.
// And when merge group-1.
// merge change parent.

class Solution {
public:
    int p[205];
    int find(int x){
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        memset(p, -1, sizeof p);
        int cnt = n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(i != j && M[i][j]){
                    int a = find(i), b = find(j);
                    if(a == b) continue;
                    p[b] = a;
                    cnt--;
                }
        return cnt;
    }
};


// DFS, Just visited.
// O(N^2)
class Solution {
public:
    bool vis[205];
    int n;
    void dfs(vector<vector<int>>& M, int u){
        vis[u] = true;
        for(int v = 0; v < n; ++v){
            if(vis[v] || !M[u][v]) continue;
            dfs(M, v);
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        n = M.size();
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(!vis[i]) dfs(M, i), ans++;
        return ans;
    }
};
