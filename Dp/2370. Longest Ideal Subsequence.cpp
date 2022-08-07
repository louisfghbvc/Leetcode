// O(N), top down memo

class Solution {
public:
    int longestIdealString(string s, int k) {
        // goal: find the longest subsequence
        // adjacent letter order is 
        
        // observe that order is doesn't matter -> no
        // idea:
        // dp 
        
        // dp[i][prev letter]
        // choose cur or not
        
        int n = s.size();
        vector dp(n, vector(27, -1));
        auto dfs = [&](const auto &self, int i, int prev=0) {
            if (i >= n) return 0;
            
            int &res = dp[i][prev];
            if (res != -1) return res;
            
            // no choose
            res = self(self, i+1, prev);
            int d = s[i]-'a'+1;
            if (prev == 0 || abs(prev-d) <= k)
                res = max(res, 1+self(self, i+1, d));
            return res;
        };
        
        return dfs(dfs, 0, 0);
    }
};
