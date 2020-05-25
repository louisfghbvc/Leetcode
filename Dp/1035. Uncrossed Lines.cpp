// Just LCS concept.
// make length more bigger
// if A[i] == B[j], dp[i][j] = dp[i-1][j-1] + 1

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        size_t n = A.size(), m = B.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
