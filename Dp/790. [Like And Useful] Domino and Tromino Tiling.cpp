// observe pattern.
// use math formula

class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        if(n <= 2) return n;
        
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; ++i)
            dp[i] = ((long)dp[i-1] * 2 + dp[i-3]) % mod; 
        
        return dp.back();
    }
};

// define two functions, from base
// see pic https://hackmd.io/Du0IHEqDT8yqmI74koDZZw#%E8%BC%AA%E5%BB%93DP
// O(N)

class Solution {
public:
    int mod = 1e9+7;
    int numTilings(int n) {
        if(n <= 1) return n;
        
        vector<int> g(n+1), m(n+1);
        for(int i = 1; i <= 2; ++i)
            g[i] = m[i] = i;
        
        for(int i = 3; i <= n; ++i){
            // use domino, trimino
            g[i] = ((long)(g[i-1] + g[i-2]) + (long)2*m[i-2]) % mod;
            m[i] = ((long)g[i-1] + m[i-1]) % mod;
        }
        
        return g[n];
    }
};
