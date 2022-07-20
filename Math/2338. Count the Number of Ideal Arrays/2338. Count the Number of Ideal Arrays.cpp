class Solution {
public:
    
    const int mod = 1e9+7;
    vector<long> fac, ifac; // fac[i]: i!
    long nCr(int n, int r) {
        return fac[n] * ifac[r] % mod * ifac[n-r] % mod;
    }
    
    long fpow(long a, int b) {
        long res = 1;
        while (b) {
            if (b&1) res = res*a % mod;
            b >>= 1;
            a = a*a % mod;
        }
        return res;
    }
    
    int idealArrays(int n, int maxValue) {
        // ideal: every value between 1 to maxValue
        // arr[i] % arr[i-1] == 0
        
        // idea: build length 14 dp which is strictly increasing
        // we only have 2^0, 2^1..... 2^13
        // and then use [1,2,4] -> to length 5
        // add two bars _ _ | _ | _ _ -> 1 1 | 2 | 4 4
        // nCr = 4!/2!2!
        
        // div[i]: all divisors exclude self
        vector<vector<int>> div(maxValue+1);
        for (int i = 1; i <= maxValue; ++i)
            for (int j = 2*i; j <= maxValue; j += i)
                div[j].push_back(i);
        
        fac.resize(n+1);
        ifac.resize(n+1);
        
        fac[0] = 1;
        for (int i = 1; i <= n; ++i)
            fac[i] = fac[i-1] * i % mod;
        
        ifac[n] = fpow(fac[n], mod-2); // mod inv
        for (int i = n; i >= 1; --i)
            ifac[i-1] = ifac[i] * i % mod;
        
        // dp[i][value]: length i, ending number is value
        vector<vector<long>> dp(15, vector<long>(maxValue+1));
        for (int i = 1; i <= maxValue; ++i)
            dp[1][i] = 1;
        
        for (int i = 2; i <= 14 && i <= n; ++i) {
            for (int j = 1; j <= maxValue; ++j) {
                for (int d: div[j])
                    (dp[i][j] += dp[i-1][d]) %= mod;
            }
        }
        
        long res = 0;
        for (int i = 1; i <= 14 && i <= n; ++i) {
            // ending value doesn't matter
            for (int j = 1; j <= maxValue; ++j)
                (dp[i][0] += dp[i][j]) %= mod;
            
            // n-1 choose i-1 bars
            res += nCr(n-1, i-1) * dp[i][0] % mod;
            res %= mod;
        }
        return res;
    }
};
