//O(nmkm), Useful. Common
//Space(nmk)
class Solution {
public:
    int dp[55][105][55];
    const int mod = 1e9+7;
    //a: index, b: cur_max, c: cur_searchcnt
    int dfs(int a, int b, int c, int& n, int& m, int& k){
        if(a == n && c == k) return 1;
        if(a >= n || c > k) return 0;
        if(dp[a][b][c] != -1) return dp[a][b][c];
        
        long res = 0;
        for(int i = 1; i <= m; ++i){
            int nmx = b;
            int ncost = c;
            if(i > nmx){
                nmx = i;
                ncost++;
            }
            res += dfs(a+1, nmx, ncost, n, m, k);
            res %= mod;
        }
        
        return dp[a][b][c] = res;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, 0, n, m, k);
    }
};
