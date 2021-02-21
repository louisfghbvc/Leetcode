// O(N^2). LPS... stuck in left right case but no idea cuz I use LCS.
// this is more clean and simple.
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
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
        
        int res = 0;
        for(int i = 0; i < word1.size(); ++i){
            for(int j = 0; j < word2.size(); ++j){
                if(s[i] == s[word1.size()+j]){
                    res = max(res, dp[i][word1.size()+j]);
                }
            }
        }
        
        return res <= 1 ? 0 : res;
    }
};


// O(N^2). Clean. But I like above version.
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        int res = 0;
        for(int r = 0; r < n; ++r){
            dp[r][r] = 1;
            for(int l = r-1; l >= 0; --l){
                if(s[l] == s[r]){
                    dp[l][r] = (l+1 == r) ? 2 : dp[l+1][r-1] + 2;
                    if(l < word1.size() && r >= word1.size()){
                        res = max(res, dp[l][r]);
                    }
                }
                else{
                    dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
                }
            }
        }
        
        return res;
    }
};
