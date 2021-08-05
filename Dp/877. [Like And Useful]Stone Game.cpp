// Game dp. O(N^2).
class Solution {
public:
    
    vector<int> arr;
    vector<vector<int>> dp;
    vector<vector<bool>> vis;
    
    int dfs(int l, int r){
        if(l > r) return 0;
        if(vis[l][r]) return dp[l][r];
        vis[l][r] = 1;
        return dp[l][r] = max(arr[l] - dfs(l+1, r), arr[r] - dfs(l, r-1));
    }
    
    bool stoneGame(vector<int>& piles) {
        arr = piles;
        int n = arr.size();
        vis = vector<vector<bool>>(n, vector<bool>(n));
        dp = vector<vector<int>>(n, vector<int>(n));
        return dfs(0, n-1) > 0;
    }
};


// Backward deduction. since even. if 2 alice always win.
