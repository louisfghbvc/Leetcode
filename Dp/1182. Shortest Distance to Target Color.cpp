// Two pass, record closest color position.
// O(N + Q).

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        
        // first pass we try from left to right. update colors
        vector<vector<int>> dp(3, vector<int>(n, 1e9));
        dp[colors[0]-1][0] = 0;
        for(int i = 1; i < n; ++i){
            for(int c = 0; c < 3; ++c){
                dp[c][i] = min(dp[c][i-1] + 1, dp[c][i]);
            }
            dp[colors[i]-1][i] = 0;
        }
        dp[colors[n-1]-1][n-1] = 0;
        for(int i = n-2; i >= 0; --i){
            for(int c = 0; c < 3; ++c){
                dp[c][i] = min(dp[c][i+1] + 1, dp[c][i]);
            }
            dp[colors[i]-1][i] = 0;
        }
        
        vector<int> res;
        for(auto &q: queries){
            int color = q[1]-1, ind = q[0];
            int tmp = dp[color][ind];
            res.push_back(tmp >= 1e9 ? -1 : tmp);
        }
        return res;
    }
};
