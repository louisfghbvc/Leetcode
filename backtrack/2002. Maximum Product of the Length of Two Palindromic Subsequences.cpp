// Backtracking, since constraint is small

class Solution {
public:
    
    bool isP(string &s){
        for(int i = 0; i < s.size() / 2; ++i){
            if(s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
    
    int dp[12][12];
    int dfs(string &s, int l, int r){
        if(l > r) return 0;
        if(l == r) return 1;
        if(l+1 == r && s[l] == s[r]) return 2;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r])
            return dp[l][r] = 2 + dfs(s, l+1, r-1);
        return dp[l][r] = max(dfs(s, l+1, r), dfs(s, l, r-1));
    }
    
    int maxProduct(string s) {
        int n = s.size();
        int res = 0;
        for(int mask = 0; mask < 1<<n; ++mask){
            string a = "";
            for(int i = 0; i < n; ++i){
                if(mask >> i & 1) a += s[i];
            }
            if(!isP(a)) continue;
            
            int other = (~mask) & ((1<<n)-1);
            memset(dp, -1, sizeof dp);
            string b = "";
            for(int i = 0; i < n; ++i){
                if(other >> i & 1) b += s[i];
            }
            res = max(res, (int)a.size() * dfs(b, 0, b.size()-1));
        }
        return res;
    }
};
