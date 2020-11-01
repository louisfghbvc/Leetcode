// Simple dp. 
// O(N)
class Solution {
public:
    int dp[10][55];
    int dfs(int i, int len, int n){
        if(len == n) return 1;
        if(dp[i][len] != -1) return dp[i][len];
        int res = 0;
        for(int id = i; id < 5; ++id)
            res += dfs(id, len+1, n);
        return dp[i][len] = res;
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof dp);
        return dfs(0, 0, n);
    }
};

// Can just use backtraking. since n = 50.
