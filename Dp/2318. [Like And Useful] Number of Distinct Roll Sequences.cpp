class Solution {
public:
    int distinctSequences(int n) {
        // goal: build the number of distinct sequence such that adjcacent value gcd = 1
        // same value distance > 2
        
        // idea: backtracking
        // O(6^N) -> TLE
        // memo -> O(N*6*6*6)
        
        int mod = 1e9+7;
        
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(7, vector<long>(7, -1)));
        
        auto dfs = [&](const auto &self, int i, int p0, int p1) -> long { // p0=i-2, p1=i-1
            if (i == n) return 1; // base
            
            long &res = dp[i][p0][p1]; // memo
            if (res != -1) return res;
            
            res = 0;
            if (i == 0) {
                for (int d = 1; d <= 6; ++d)
                    res = (res + self(self, i+1, 0, d)) % mod;
            }
            else if (i == 1) {
                for (int d = 1; d <= 6; ++d) if (d != p1 && __gcd(d, p1) == 1) 
                    res = (res + self(self, i+1, p1, d)) % mod;
            }
            else {
                for (int d = 1; d <= 6; ++d) if (d != p1 && __gcd(d, p1) == 1 && d != p0)  
                    res = (res + self(self, i+1, p1, d)) % mod;
            }
            
            return res;
        };
        
        return dfs(dfs, 0, 0, 0);
    }
};
