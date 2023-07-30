class Solution {
public:
    
    int mod = 1e9+7;
    
    int cal(string &s) {
        int n = s.size();
        vector dp(n, vector(10, vector(2, vector(2, -1))));
            
        auto dfs = [&](auto &self, int i = 0, int prev=0, bool is_bound = true, bool leading_zero = true) -> int {
            if (i >= n) return !leading_zero;
            
            int &res = dp[i][prev][is_bound][leading_zero];
            if (res != -1) return res;
            
            res = 0;
            int cur = is_bound ? s[i]-'0' : 9;
            for (int d = 0; d <= cur; ++d) {
                if (!leading_zero && abs(d-prev) != 1) continue;
                // leading_zero = true, 0-9 || abs(d-prev) == 1
                bool next_bound = is_bound && d == s[i]-'0';
                bool next_leading_zero = leading_zero && d == 0;
                res = (res + self(self, i+1, d, next_bound, next_leading_zero)) % mod;
            }
            
            return res;
        };
        
        return dfs(dfs);
    };
    
    int countSteppingNumbers(string low, string high) {
        // goal: count the stepping numbers each digit abs diff is exactly 1
        
        // 1, 2, ans=2
        
        // idea: digit dp
        // F(x): number of positive integer <= x that is stepping numbers
        // ans = F(high) - F(low) + isStepping nubmer(low) 
        
        // numbers of starting from index i
        // isbound: all maxmimum digit, e.g 123, 12? or 1?? or 123, false -> enumerate 0-9 otherwise only s[i]
        // 1  2 3 
        //        ^
        //.0  0 0   
        // 
        // dfs(i, prev_digit, isbound, isleading_zero) 
        //    
        
        int ans = (cal(high) - cal(low)) % mod;
        if (ans < 0) ans += mod;
        
        bool good = true;
        for (int i = 1; i < low.size(); ++i)
            if (abs(low[i]-low[i-1]) != 1) good = false;
        ans = (ans + good) % mod;
        return ans;
    }
};
