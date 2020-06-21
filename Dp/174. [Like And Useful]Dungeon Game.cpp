// omg so amaze...
// O(MN). Backward so that we can know the hp, minimum need
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1e9));
        
        dp[m][n-1] = dp[m-1][n] = 1;
        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need <= 0 ? 1 : need;
            } 
        }
        
        return dp[0][0];
    }
};

// Straight Forward. Binary Search + dp
// if dp[i][j-1] <= 0 and dp[i][j-1] <= 0 then dp[i][j] must can not go. whenever current matrix is postive
// the concept is find max.
// find max. try to find minimum positive.
// O(MNlogK)
class Solution {
public:
    bool ok(vector<vector<int>> &dungeon, int val){
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = dungeon[0][0] + val;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i > 0 && dp[i-1][j] > 0)
                    dp[i][j] = max(dp[i][j], dungeon[i][j] + dp[i-1][j]);
                if(j > 0 && dp[i][j-1] > 0)
                    dp[i][j] = max(dp[i][j], dungeon[i][j] + dp[i][j-1]);
            } 
        }
        // cout << val << " " << dp[m-1][n-1] << endl;
        return dp[m-1][n-1] > 0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int l = 1, r = INT_MAX, res = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ok(dungeon, mid)){
                r = mid-1;
                res = mid;
            }
            else{
                l = mid+1;
            }
        }
        return res;
    }
};
