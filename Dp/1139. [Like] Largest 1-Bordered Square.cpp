// only record row prefix and col prefix sum
// and just check 3 edge point
// first check right-bottom point
// O(MNL)

class Solution {
public:
    typedef pair<int, int> ii;
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<ii>> dp(m, vector<ii>(n));
        // dp[i][j].first: row sum, second: col sum
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    dp[i][j].second = j ? dp[i][j-1].second+1 : 1;
                    dp[i][j].first = i ? dp[i-1][j].first+1 : 1;
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int val = min(dp[i][j].first, dp[i][j].second);
                while(val > res){
                    if(dp[i-val+1][j].second >= val && dp[i][j-val+1].first >= val)
                        res = val;
                    val--;
                }                
            }
        }
        
        return res*res;
    }
};
