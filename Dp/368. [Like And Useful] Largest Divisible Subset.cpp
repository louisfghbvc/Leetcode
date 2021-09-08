// O(N^2). LIS. and record path.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        
        // dp[i]: longest length, end with i
        vector<int> dp(n); 
        // path[i]: longest length, parent
        vector<int> path(n); 
        
        // maximum length index.
        int mxi = 0;
        for(int i = 0; i < n; ++i){
            dp[i] = 1;
            path[i] = -1;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){ // can from j
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        path[i] = j;
                    }
                }
            }
            if(dp[i] > dp[mxi]){
                mxi = i;
            }
        }
        
        // no order, just push back
        for(; mxi != -1; mxi = path[mxi]){
            res.push_back(nums[mxi]);
        }
        return res;
    }
};
