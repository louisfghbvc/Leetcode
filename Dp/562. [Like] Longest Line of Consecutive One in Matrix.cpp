// 3D dp. just need to record 4 direction.
// T: O(MN). S: O(MN)

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        if(mat.empty()) return 0;
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(m)));
        
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!mat[i][j]) continue;
                dp[0][i][j] = (i && j) ? dp[0][i-1][j-1]+1 : 1;
                dp[1][i][j] = i ? dp[1][i-1][j]+1: 1;
                dp[2][i][j] = j ? dp[2][i][j-1]+1: 1;
                dp[3][i][j] = (i && j+1 < m) ? dp[3][i-1][j+1]+1: 1;
                ans = max({ans, dp[0][i][j], dp[1][i][j], dp[2][i][j], dp[3][i][j]});
            }
        }
        
        return ans;
    }
};


// Use map. i, j, i+j, i-j.
