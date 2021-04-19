// Top down dp. O(target * N).

class Solution {
public:
    vector<int> dp;
    
    int dfs(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int res = 0;
        for(int x: nums){
            if(target-x >= 0)
                res += dfs(nums, target-x);
        }
        return dp[target] = res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int>(target+1, -1);
        return dfs(nums, target);
    }
};
