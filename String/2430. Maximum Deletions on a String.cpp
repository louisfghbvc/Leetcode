// Dp of Dp, Build longest prefix table O(N^2)

class Solution {
public:
    int deleteString(string s) {
        // goal: find the maximum of split
        // idea: pre compute the lcp[i][j] -> longest common prefix
        
        int n = s.size();
        vector lcp(n+1, vector(n+1, 0)); // lcp[i][j]: from matching index i, prefix of length in index j
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j])
                    lcp[i][j] = 1 + lcp[i+1][j+1];
                else
                    lcp[i][j] = 0;
            }
        }
        
        
        vector dp(n, -1);
        auto dfs = [&](auto &self, int start) {
            if (start == n) return 0;
            
            int &res = dp[start];
            if (res != -1) return res;
            
            res = 1; // base, entire string
            for (int i = start+1; i < n; ++i) {
                int len = i - start;
                if (lcp[start][i] >= len)
                    res = max(res, 1 + self(self, start + len));
            }
            
            return res;
        };
        
        return dfs(dfs, 0);
    }
};


// O(N^2)
// Z algorithm
class Solution {
public:
    int deleteString(string s) {
        // goal: find the maximum deletion
        // idea: 
        // each time of dp -> common prefix string
        // dp
        
        int n = s.size();
        vector dp(n, -1);
        
        auto dfs = [&](auto &self, int start) {
            if (start == n) return 0;
            
            int &res = dp[start];
            if (res != -1) return res;
            
            res = 1; // base case split entire string
            vector<int> z(n);
            
            int l = start, r = start;
            for (int i = start+1; i < n; ++i) {
                if (i <= r)
                    z[i] = min(r - i + 1, z[start + i - l]);
                while (i + z[i] < n && s[start + z[i]] == s[i + z[i]])
                    ++z[i];
                if (i + z[i] - 1 > r)
                    l = i, r = i + z[i] - 1;
                
                int len = i-start;
                if (z[i] >= len) { 
                    res = max(res, 1 + self(self, start+len));
                }
            }
            
            return res;
        };
        
        return dfs(dfs, 0);
    }
};
