// Bottom up dp. think about O(N^2).
// Observe that, dp[i] = max(pre[j] - dp[j]), j = i+1~N
// So, from backward is no duplicate and fast.
// Dp can optimize

class Solution {
public:
    
    int n;
    vector<int> dp;
    vector<int> pre;
    
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        int res = 0;
        
        pre = vector<int>(n);
        pre[0] = stones[0];
        for(int i = 1; i < n; ++i){
            pre[i] = pre[i-1] + stones[i];
        }
        
        dp = vector<int>(n, INT_MIN);
        
        dp[n-1] = 0;
        int mx = pre[n-1];
        for(int i = n-2; i >= 0; --i){
            dp[i] = mx;
            mx = max(mx, pre[i] - dp[i]);
        }
        
        return dp[0];
    }
};
