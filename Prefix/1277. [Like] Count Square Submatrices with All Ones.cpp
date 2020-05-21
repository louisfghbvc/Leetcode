// O(N^3). check all length square.
// slower, but simple.
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int res = 0, len = min(m, n);
        for(int l = 1; l <= len; ++l){
            for(int i = 0; i+l <= n; ++i){
                for(int j = 0; j+l <= m; ++j){
                    int ar = pre[i+l][j+l] - pre[i][j+l] - pre[i+l][j] + pre[i][j];
                    if(ar == l*l) res++;
                }
            }
        }
        return res;
    }
};

// O(N^2). DP, Impressive...
// Optimal, dp is simple from min left or top or top-left + 1
// then sum dp.
// assume dp[i][j] = 5, means there are 5 squares. just a dp by-product(副產物).

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == 1){
                    dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + 1;
                    res += dp[i+1][j+1];
                }
                else{
                    dp[i+1][j+1] = 0;
                }
            }
        }
        return res;
    }
};
