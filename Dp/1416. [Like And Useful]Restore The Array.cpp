//Memorize. Think base, and merge.
class Solution {
public:
    const int mod = 1e9 + 7;
    int dfs(int i, const string &s, long k, vector<int>& dp){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        
        long res = 0, num = 0;
        for(int j = i; j < s.size(); ++j){
            num = num * 10 + (s[j]-'0');
            if (num > k) break; // cut
            res += dfs(j+1, s, k, dp);
            res %= mod;
        }
        return dp[i] = res;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size(), -1);
        dfs(0, s, k, dp);
        return dp[0];
    }
};
