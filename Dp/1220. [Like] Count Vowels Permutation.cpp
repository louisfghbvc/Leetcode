// Think it as graph. and top down dp O(N).
// Can reduce space.

class Solution {
public:
    // a -> 1, e -> 2, i -> 3, o -> 4, u -> 5
    int n;
    const int mod = 1e9+7;
    
    vector<vector<int>> dp;
    int dfs(int i, int cur = 0){
        if(i == n) return 1;
        if(dp[i][cur] != -1) return dp[i][cur];
        
        long res = 0;
        if(cur == 0){
            for(int k = 1; k <= 5; ++k)
                res = (res + dfs(i+1, k)) % mod;
        }
        else if(cur == 1){ // a->e
            res = (res + dfs(i+1, 2)) % mod;
        }
        else if(cur == 2){ // e->a, or e->i
            res = (res + dfs(i+1, 1)) % mod;
            res = (res + dfs(i+1, 3)) % mod;
        }
        else if(cur == 3){
            for(int k = 1; k <= 5; ++k) if(k != 3){
                res = (res + dfs(i+1, k)) % mod;
            }
        }
        else if(cur == 4){ // o->i, o->u
            res = (res + dfs(i+1, 3)) % mod;
            res = (res + dfs(i+1, 5)) % mod;
        }
        else{
            res = (res + dfs(i+1, 1)) % mod;
        }
        
        return dp[i][cur] = res;
    }
    
    int countVowelPermutation(int n) {
        dp = vector<vector<int>>(n, vector<int>(6, -1));
        this->n = n;
        return dfs(0);
    }
};
