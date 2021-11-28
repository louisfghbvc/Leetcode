// O(MN). space O(N)
// build it as 11111
//              222
//               3
// we just check middle and calculate height.

class Solution {
public:
    int helper(vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<int> dp = grid[0];
        for(int i = 1; i < m; ++i){
            auto ndp = grid[i];
            for(int j = 1; j+1 < n; ++j){
                if(dp[j] && ndp[j]){
                    ndp[j] = min(dp[j-1], dp[j+1]) + 1;
                    res += ndp[j]-1;
                }
            }
            dp = ndp;
        }
        
        return res;
    }
    
    int countPyramids(vector<vector<int>>& grid) {
        int res = helper(grid);
        reverse(grid.begin(), grid.end());
        return res + helper(grid);
    }
};

// use prefix sum + binary search/math
// O(MN), space O(N)
