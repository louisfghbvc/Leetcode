// DP O(N^2). simple top down. minimax strategy. just max(me - ohter).
// use prefix to fast. also no need suffix. can just prefix and tot.
// Python MLE. QAQ.

class Solution {
public:
    vector<int> arr;
    vector<int> pre;
    vector<int> suf;
    
    int tot;
    int dp[1005][1005];
    bool vis[1005][1005];
    int dfs(int l, int r){
        if(l > r) return 0;
        if(vis[l][r]) return dp[l][r];
        vis[l][r] = 1;
        int remain = tot - (pre[l]-arr[l]) - (suf[r]-arr[r]);
        int res = remain - arr[l] - dfs(l+1, r);
        res = max(res, remain - arr[r] - dfs(l, r-1));
        
        return dp[l][r] = res;
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        tot = accumulate(stones.begin(), stones.end(), 0);
        arr = stones;
        
        pre = vector<int>(n, 0);
        suf = pre;
        
        pre[0] = arr[0];
        for(int i = 1; i < n; ++i) pre[i] = pre[i-1] + arr[i];
        suf[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) suf[i] = suf[i+1] + arr[i];
        
        return dfs(0, n-1);
    }
};

