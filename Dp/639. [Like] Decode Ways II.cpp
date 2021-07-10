// Enum case. O(N). Top down + Memo.

class Solution {
public:
    const int mod = 1e9+7;
    
    string s;
    vector<int> dp;
    int dfs(int i){
        if(i >= s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        bool star = s[i] == '*';
        long res = (star ? 9L : 1L) * dfs(i+1) % mod;
        if(s[i] == '1' || star){
            if(i+1 < s.size()){
                if(s[i+1] == '*') res += 9L * dfs(i+2);
                else res += dfs(i+2);
                res %= mod;
            }
        }
        if(s[i] == '2' || star){
            if(i+1 < s.size()){
                if(s[i+1] == '*') res += 6L * dfs(i+2);
                else if(s[i+1] >= '0' && s[i+1] <= '6') res += dfs(i+2);
                res %= mod;
            }
        }
        
        return dp[i] = res;
    }
    
    int numDecodings(string s) {
        this->s = s;
        dp = vector<int>(s.size(), -1);
        return dfs(0);
    }
};
