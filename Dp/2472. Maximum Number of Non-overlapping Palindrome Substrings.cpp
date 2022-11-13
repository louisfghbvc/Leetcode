class Solution {
public:
    int maxPalindromes(string s, int k) {
        // goal: choose the maximum of palindrome substring
        // idea: dp
        // dp[i]: starting from index i, what is maximum palindrome so far
        
        // step1, build palindrome table
        // step2, compute the dp
        
        int n = s.size();
        vector is_pal(n, vector(n, false));
        for (int i = 0; i < n; ++i)
            is_pal[i][i] = true;
        for (int i = 0; i+1 < n; ++i)
            is_pal[i][i+1] = (s[i] == s[i+1]);
        for (int l = 2; l < n; ++l) {
            for (int i = 0; i+l < n; ++i) {
                if (s[i] == s[i+l] && is_pal[i+1][i+l-1])
                    is_pal[i][i+l] = true;
            }
        }
        
        vector dp(n, -1);
        // dp[i]: choose some j such that Pal(i, j) + dp[j]
        auto dfs = [&](auto &self, int i) {
            if (i >= n) return 0; 
            
            int &res = dp[i];
            if (res != -1) return res;
            
            // skip index i
            res = self(self, i+1); 
            
            // use index i
            for (int j = i; j < n; ++j) {
                if (is_pal[i][j] && j-i+1 >= k)
                    res = max(res, 1 + self(self, j+1));
            }
            
            return res;
        };
        
        return dfs(dfs, 0);
    }
};
