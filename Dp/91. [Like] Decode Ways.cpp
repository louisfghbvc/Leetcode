// O(N). Space O(N). Dp
// two case use i or use i,i+1
// like fib.
class Solution {
public:
    string s;
    int dp[105];
    int dfs(int i){
        if(s[i] == '0') return 0;
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        
        int res = dfs(i+1);
        if(i+2 <= s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) res += dfs(i+2);
        
        return dp[i] = res;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        this->s = s;
        return dfs(0);
    }
};
