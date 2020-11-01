// Observe that compress all col to one frequency.
// and just dp. skip or not skipped. use target to construct. 
// O(N^2). Space(O^2).

class Solution {
public:
    int mod = 1e9+7;
    int dp[1005][1005];
    int cnt[1005][26];
    int n;
    
    long dfs(int i, int j, string &t){
        if(j == t.size()) return 1;
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int id = t[j]-'a';
        long res = dfs(i+1, j, t);
        if(cnt[i][id])
            res = (res + dfs(i+1, j+1, t) * cnt[i][id]) % mod;
        return dp[i][j] = res;    
    }
    
    int numWays(vector<string>& words, string target) {
        memset(dp, -1, sizeof dp);
        n = words[0].size();
        
        for(auto & wd: words)
            for(int i = 0; i < wd.size(); ++i)
                cnt[i][wd[i]-'a']++;
        
        return dfs(0, 0, target);
    }
};

// O(N^2). Space O(N)
