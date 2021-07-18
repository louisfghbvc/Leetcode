// Can more clean. O(NM).
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size();
        int c = points[0].size();
        
        vector<vector<long>> dp(r, vector<long>(c));
        for(int j = 0; j < c; ++j){
            dp[0][j] = points[0][j];
            if(j) dp[0][j] = max(dp[0][j], dp[0][j-1] - 1);
        }
        for(int j = c-1; j >= 0; --j){
            if(j != c-1) 
                dp[0][j] = max(dp[0][j], dp[0][j+1] - 1);
        }
        
        for(int i = 1; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(j == 0) dp[i][j] = dp[i-1][j] + points[i][j];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - 1) + points[i][j];
                    dp[i][j] = max(dp[i][j-1] - 1, dp[i][j]);
                }
            }
            for(int j = c-1; j >= 0; --j){
                if(j == c-1) dp[i][j] = max(dp[i][j], dp[i-1][j] + points[i][j]);
                else{
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1] - 1 + points[i][j]);
                    dp[i][j] = max(dp[i][j+1] - 1, dp[i][j]);
                }
            }
        }
        
        return *max_element(dp[r-1].begin(), dp[r-1].end());
    }
};

// Space can be O(N).
