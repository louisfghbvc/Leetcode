class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        // goal: count the number such that we can reduce the value to 1 at most k times
        
        // idea: digit dp
        // dp[i][isbound][isZ][cnt]: number of ways, starting from index i, is leading zero
        
        int mod = 1e9+7;
        
        int n = s.size();
        vector dp(n, vector(2, vector(2, vector(n+1, -1))));
        
        auto eval = [&](int x) {
            int cnt = 1;
            while (x != 1) {
                cnt++;
                x = __builtin_popcount(x);
            }   
            return cnt;
        };
        
        auto dfs = [&](auto &self, int i, int isB, int isZ, int cnt) -> int {
            if (i >= n) return (!isZ && eval(cnt) <= k);
            
            auto& res = dp[i][isB][isZ][cnt];
            if (res != -1) return res;
            
            res = 0;
            int b = isB ? s[i]-'0' : 1;
            for (int d = 0; d <= b; ++d) {
                int nB = isB && (d == s[i]-'0');
                int nisZ = isZ && (d == 0);
                // speical case one
                if (i == n-1 && isZ && d == 1)
                    res = (res + 1) % mod;
                else
                    res = (res + self(self, i+1, nB, nisZ, cnt + (d==1))) % mod;
            }
            
            return res;
        };
        
        // check if self is reducible
        int one = count(s.begin(), s.end(), '1');
        
        return (dfs(dfs, 0, 1, 1, 0) - (eval(one)<=k) + mod) % mod;
    }
};
