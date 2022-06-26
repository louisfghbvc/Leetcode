class Solution {
public:
    int countHousePlacements(int n) {
        // goal: calculate the number of ways that can put house such that no adjacent house 
        // in the same side
        // idea: dp
        // dp[i][top][down]: numbers of way i plot so far, ith plot put top and down or not
        
        int mod = 1e9+7;
        
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(2, vector<long>(2, -1))); // -1: unvisited
        
        auto dfs = [&](const auto &self, int i, int top=0, int down=0) -> long {
            if (i == n) return 1; 
            
            long &res = dp[i][top][down];
            if (res != -1) return res;
            
            res = self(self, i+1, 0, 0); // current no put anything
            if (!down) res = (res + self(self, i+1, 0, 1)) % mod;
            if (!top) res = (res + self(self, i+1, 1, 0)) % mod;
            if (!top && !down) res = (res + self(self, i+1, 1, 1)) % mod; // put both
            
            return res;
        };
        
        return dfs(dfs, 0, 0, 0);
    }
};

// O(N), Fib. top, down is independent
class Solution {
public:
    const int mod = 1e9+7;
    
    long fib(int x) {
        if (x <= 1) return 1;
        int f0 = 1, f1 = 1, f;
        for (int i = 2; i <= x; ++i) {
            f = (f0 + f1) % mod;
            f0 = f1;
            f1 = f;
        } 
        return f;
    }
    
    int countHousePlacements(int n) {
        long x = fib(n+1);
        return x * x % mod;
    }
};
