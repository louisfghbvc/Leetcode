// Top-Down made it simple.
// Memorize check duplicate
// O(d*f*target).
// like coin change.
class Solution {
public:
    const int mod = 1e9+7;
    int D, F;
    int dp[1005][35];
    int dfs(int t, int i){
        if(t == 0) {
            return i == D;
        }
        if(i > D) return 0;
        if(dp[t][i] != -1) return dp[t][i];
        int res = 0;
        for(int f = 1; f <= F && f <= t; ++f){
            res = (res + dfs(t-f, i+1)) % mod;
        }
        return dp[t][i] = res;
    }
    int numRollsToTarget(int d, int f, int target) {
        D = d, F = f;
        memset(dp, -1, sizeof dp);
        return dfs(target, 0);
    }
};

// Bottom up.
// Same as coin change.
class Solution {
public:
    const int mod = 1e9+7;
    int dp[35][1005];
    int numRollsToTarget(int D, int F, int target) {
        dp[0][0] = 1;
        for(int d = 1; d <= D; ++d){
            for(int f = 1; f <= F; ++f){
                for(int w = f; w <= target; ++w){
                    dp[d][w] = (dp[d][w] + dp[d-1][w-f]) % mod; 
                }
            }
        }
        return dp[D][target];
    }
};

// Space optimal. Can be O(N). rolling dp
class Solution {
public:
    const int mod = 1e9+7;
    int numRollsToTarget(int D, int F, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int d = 1; d <= D; ++d){
            vector<int> dp1(target+1);
            for(int f = 1; f <= F; ++f){
                for(int w = target; w >= f; --w){
                    dp1[w] = (dp1[w] + dp[w-f]) % mod; 
                }
            }
            swap(dp, dp1);
        }
        return dp[target];
    }
};
