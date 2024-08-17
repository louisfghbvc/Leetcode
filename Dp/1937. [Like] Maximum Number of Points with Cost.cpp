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

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // goal: find the maximum points each row must pick one cells
        // idea: dp
        // dp[i][j]: maximum points we can get ending at (i, j)
        // dp[i][j] = dp[i-1][k] + abs(k-j), k = 0~n-1, 
        // we can using prefix to speed up the transition -> we can do twice from left and right
        // dp[i-1][k] = max(dp[i-1][k], dp[i-1][k-1]+1)

        // wait -> we may have easier way
        // prefix
        // remove abs, so dp[i][j] = max of (dp[i-1][k] - (j-k)), k<j
        // remove abs, so dp[i][j] = -j + max of (dp[i-1][k] + k), k<j

        // suf
        // k>j
        // max of (dp[i-1][k] - (k-j)) => 

        int m = points.size();
        int n = points[0].size();
        vector<long> dp(points[0].begin(), points[0].end());

        for (int i = 1; i < m; ++i) {
            vector<long> ndp(n);
            // do prefix
            long pre = -1e9;
            for (int j = 0; j < n; ++j) {
                pre = max(dp[j] + j, pre);
                ndp[j] = max(ndp[j], points[i][j] - j + pre);
            }
            long suf = -1e9;
            for (int j = n-1; j >= 0; --j) {
                suf = max(dp[j] - j, suf);
                ndp[j] = max(ndp[j], points[i][j] + j + suf);
            }
            swap(dp, ndp);
        }

        return ranges::max(dp);
    }
};
