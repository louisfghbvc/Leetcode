class Solution {
public:
    void dfs(int &res, vector<bool> &vis, int d, int &n){
        if(d == 0){
            res++;
            return;
        }
        for(int i = n; i >= 1; ++i){
            if(vis[i-1]) continue;
            if((i % d && d % i)) continue;
            vis[i-1] = true;
            dfs(res, vis, d - 1, n);
            vis[i-1] = false;
        }
    }
    int countArrangement(int N) {
        vector<bool> vis(N, false);
        int ans = 0;
        dfs(ans, vis, N, N);
        return ans;
    }
};
