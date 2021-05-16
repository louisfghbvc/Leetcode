// So, put from rightmost is more simple than put from left.
// O(NK). tricky.

class Solution {
public:
    
    vector<vector<long>> dp;
    const int mod = 1e9+7;
    long dfs(int n, int k){
        if(n == 1) return k == 1; // base
        if(k == 0) return 0; // base
        if(dp[n][k] != -1) return dp[n][k];
        long res = dfs(n-1, k-1); // rightmost put tallest.
        res += dfs(n-1, k) * (n-1);
        res %= mod;
        return dp[n][k] = res;
    }
    
    int rearrangeSticks(int n, int k) {
        dp = vector<vector<long>> (n+1, vector<long>(k+1, -1));
        return dfs(n, k);
    }
};
