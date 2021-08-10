// Prefix sum.
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> zero(n+1); // to 0 cost
        vector<int> one(n+1);
        
        for(int i = 1; i <= n; ++i)
            zero[i] = zero[i-1] + (s[i-1] != '0');
            
        for(int i = n-1; i >= 0; --i)
            one[i] = one[i+1] + (s[i] != '1');
        
        int res = 1e9;
        for(int i = 0; i <= n; ++i)
            res = min(res, zero[i] + one[i]);
        return res;
    }
};

// O(N) top down dp, but slow.
class Solution {
public:
    
    string t;
    vector<vector<int>> dp;
    int dfs(int i = 0, int prev = 0){
        if(i >= t.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int res = (t[i]-'0' != prev) + dfs(i+1, prev);
        if(t[i] != prev && prev == 0)
            res = min(res, dfs(i+1, 1));
        return dp[i][prev] = res;
    }
    
    int minFlipsMonoIncr(string s) {
        t = s;
        dp = vector<vector<int>>(t.size(), vector<int>(2, -1));
        
        return dfs();
    }
};
