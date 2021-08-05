class Solution {
public:
    
    int first, second;
    vector<int> pre;
    int n;
    
    vector<vector<vector<int>>> dp;
    
    int dfs(int i, bool useA, bool useB){
        if(i >= n) return 0;
        if(dp[i][useA][useB] != -1) return dp[i][useA][useB];
        int res = dfs(i+1, useA, useB);
        if(!useA && i + first <= n) // useA
            res = max(res, pre[i + first] - pre[i] + dfs(i + first, true, useB));
        if(!useB && i + second <= n) // useB
            res = max(res, pre[i + second] - pre[i] + dfs(i + second, useA, true));
        return dp[i][useA][useB] = res;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        first = firstLen;
        second = secondLen;
        n = nums.size();
        pre = vector<int>(n+1);
        for(int i = 1; i <= n; ++i)
            pre[i] = pre[i-1] + nums[i-1];
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return dfs(0, 0, 0);
    }
};
