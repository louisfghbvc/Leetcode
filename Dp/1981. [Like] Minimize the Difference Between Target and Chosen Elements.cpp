// use bitset to speed up
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        
        bitset<4905> dp;
        for(int j = 0; j < m; ++j)
            dp[mat[0][j]] = 1;
        
        for(int i = 1; i < n; ++i){
            bitset<4905> ndp;
            for(int j = 0; j < m; ++j){
                ndp |= (dp << mat[i][j]);
            }
            dp = ndp;
        }
        
        int res = 1e9;
        for(int i = 0; i <= 4900; ++i){
            if(dp[i])
                res = min(res, abs(i-target));
        }
        
        return res;
    }
};

// we can use dfs to prune.
