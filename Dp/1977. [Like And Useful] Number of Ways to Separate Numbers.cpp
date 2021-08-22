// Cool, lcp idea. O(N^2). Two dp.

class Solution {
public:
    const int mod = 1e9+7;
    
    int n;
    string s;
    vector<vector<int>> lcp;
    
    bool compare(int i, int j, int len){
        int pre = lcp[i][j];
        if(pre >= len) return true;
        return s[i + pre] < s[j + pre];
    }
    
    vector<vector<int>> dp;
    int dfs(int start=0, int len=1){
        if(s[start] == '0') return 0;
        if(start + len >= n) return start + len == n;

        if(dp[start][len] != -1) return dp[start][len];
        
        // append value
        int res = dfs(start, len+1);
        
        // not append value
        if(compare(start, start + len, len))
            res = (res + dfs(start + len, len)) % mod;
        else
            res = (res + dfs(start + len, len+1)) % mod;
        
        return dp[start][len] = res;
    }
    
    int numberOfCombinations(string num) {
        s = num;
        n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n+1, -1));
        
        // common prefix of s[i:] and s[j:]
        lcp = vector<vector<int>>(n+1, vector<int>(n+1));
        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if(s[i] == s[j])
                    lcp[i][j] = lcp[i+1][j+1] + 1;
            }
        }
        
        return dfs(0);
    }
};
