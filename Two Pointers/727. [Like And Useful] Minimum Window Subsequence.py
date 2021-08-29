# string top down dp, but autually is advance, so no memo
# O(NM)
class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        start, L = -1, len(s1)+1
        def dfs(i, j):
            if j == len(s2): return i
            ind = s1.find(s2[j], i+1)
            return float('inf') if ind < 0 else dfs(ind, j+1)
                
        for i, c in enumerate(s1):
            if c == s2[0]:
                j = dfs(i, 1)
                if j - i + 1 < L:
                    L, start = j - i + 1, i
        
        return "" if start < 0 else s1[start : start+L]

    
cpp
class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        // dp[i][j], is s1[0:i] has s2[0:j] subseq
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for(int i = 0; i < n; ++i){
            if(s1[i] == s2[0]){
                dp[i][0] = i;
            }
            else{
                if(i != 0) dp[i][0] = dp[i-1][0];
            }
        }
        
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if(s1[i] == s2[j])
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        int start = -1, len = 1e9;
        for(int i = 0; i < n; ++i){
            if(dp[i][m-1] != -1){
                if(i - dp[i][m-1]+1 < len){
                    start = dp[i][m-1];
                    len = i - dp[i][m-1]+1;
                }
            }
        }
        return start < 0 ? "" : s1.substr(start, len);
    }
};
