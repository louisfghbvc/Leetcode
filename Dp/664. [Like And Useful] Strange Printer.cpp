// O(N^3), interval dp

class Solution {
public:
    
    // dp[l][r] -> min(dp[l][k] + dp[k+1][r])... j = l~r-1;
    // base case: [l, r] == 1 -> 1
    // [l, r] == 2 -> 1 or 2
    
    //    aba
    //    /  \
    // ab,a a,ba
    // don't need to paint r when, [l, k], [k+1, r], s[k] == s[r]
    
    
    vector<vector<int>> dp;
    
    int dfs(int l, int r){
        if(l == r) return 1;
        else if(r-l == 1) return s[l] == s[r] ? 1 : 2;
        
        // for memo
        int &res = dp[l][r];
        if(res != -1) return res;
        
        res = 1e9;
        for(int k = l; k < r; ++k){
            res = min(dfs(l, k) + dfs(k+1, r) - (s[k] == s[r]), res);
        }
        
        return res;
    }
    
    int strangePrinter(string s) {
        this->s = s;
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return dfs(0, s.size()-1);
    }
    
private:
    string s;
};
