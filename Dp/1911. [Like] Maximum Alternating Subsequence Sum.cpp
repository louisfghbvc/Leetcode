// Can be O(1) space. this is memo

class Solution {
public:
    vector<int> arr;
    
    vector<vector<long>> dp;
    int n;
    
    long dfs(int i, bool even = 1){
        if(i >= n) return 0;
        if(dp[i][even] != -1) return dp[i][even];
        if(even)
            return dp[i][even] = max(dfs(i+1, 0) + arr[i], dfs(i+1, even));
        return dp[i][even] = max(dfs(i+1, 1) - arr[i], dfs(i+1, even));
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        arr = nums;
        dp = vector<vector<long>>(n, vector<long>(2, -1));
        
        return dfs(0);
    }
};
