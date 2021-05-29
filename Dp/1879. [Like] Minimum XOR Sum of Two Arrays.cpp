// BIT mask Dp. like tsp. Enum all mask. and try to from j.
// O(N^22N).

class Solution {
public:
    
    int n;
    
    vector<vector<int>> dp;
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        
        dp = vector<vector<int>>(n+1, vector<int>(1<<n, 1e9));
        
        dp[n][(1<<n)-1] = 0;
        
        for(int i = n-1; i >= 0; --i){
            for(int S = 0; S < 1<<n; ++S){
                for(int j = 0; j < n; ++j){
                    if(S >> j & 1){
                        dp[i][S ^ (1<<j)] = min(dp[i][S ^ (1<<j)], (nums1[i]^nums2[j]) + dp[i+1][S]);
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};
