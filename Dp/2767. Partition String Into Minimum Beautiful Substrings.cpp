class Solution {
public:
    
    bool isPower5(int x) {
        while (x % 5 == 0) x /= 5;
        return x == 1;
    }
    
    int minimumBeautifulSubstrings(string s) {
        // goal: find the minimum parition
        
        // idea: backtracking or dp
        // each position we can split or not split
        
        // dp[i]: minimum number of beautiful substring
        // dp[i] = 1 + dp[i+1] if s[i]=='1', 
        
        int n = s.size();
        vector dp(n, -1);
        auto dfs = [&](auto &self, int i) -> int {
            if (i >= n) return 0;
            if (s[i] == '0') return 1e9;
            
            int &res = dp[i];
            if (res != -1) return res;
            
            res = 1e9;
            int num = 0;
            for (int j = i; j < n; ++j) {
                num = num*2 + s[j]-'0';
                if (isPower5(num))
                    res = min(res, 1+self(self, j+1));
            }
            return res;
        };
        
        int ans = dfs(dfs, 0);
        if (ans > n) ans = -1;
        return ans;
    }
};
