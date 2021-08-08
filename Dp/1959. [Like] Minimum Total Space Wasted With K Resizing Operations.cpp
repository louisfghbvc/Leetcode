// O(N^2K). Dp. misunderstand the problem statement. and finally find out error.

class Solution {
public:
    
    int n;
    vector<int> arr;
    vector<vector<int>> dp;
    vector<int> pre;
    
    int dfs(int i, int k){
        if(i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int res = 1e9;
        int tmp = 0;
        for(int j = i; j < n; ++j){
            tmp = max(tmp, arr[j]);
            if(k > 0){ // try to use new size
                int val = (j-i+1) * tmp - (pre[j+1] -pre[i]) + dfs(j+1, k-1);
                if(res > val){
                    res = val;
                }
            }
        }
        return dp[i][k] = min(res, (n-i) * tmp - (pre[n] -pre[i]));
    }
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n = nums.size();
        arr = nums;
        pre = vector<int>(n+1);
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        for(int i = 1; i <= n; ++i)
            pre[i] = pre[i-1] + arr[i-1];
        
        return dfs(0, k);
    }
};
