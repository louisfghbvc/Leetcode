// O(N^2)
// Same as lcs
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string rs = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for(int i = 1; i <= n; ++i){
           for(int j = 1; j <= n; ++j){
               if(rs[i - 1] == s[j - 1])
                   dp[i][j] = dp[i - 1][j - 1] + 1;
               else
                   dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
           } 
        }
        return dp[n][n];
    }
};


// O(N^2). another dp. more intuitive.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for(int i = 0; i < n; ++i) dp[i][i] = 1;
        for(int l = 2; l <= n; ++l){
            for(int i = 0; i+l-1 < n; ++i){
                int j = i+l-1;
                if(s[i] == s[j] && l == 2) dp[i][j] = 2;
                else if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
