// O(M^M). Compress dp..
// map can not pass...

class Solution {
public:
    int n, m;
    int dp[1005][1005];
    bool vis[1005][1005];
    vector<int> nums;
    vector<int> mul;
    int dfs(int l, int r, int j){
        if(j >= m) return 0;
        if(vis[l][n-1-r]) return dp[l][n-1-r];
        int res = 0;
        res = max(nums[l] * mul[j] + dfs(l+1, r, j+1), nums[r] * mul[j] + dfs(l, r-1, j+1));
        vis[l][n-1-r] = 1;
        return dp[l][n-1-r] = res;
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n = nums.size();
        m = mul.size();
        this->nums = nums;
        this->mul = mul;
        memset(vis, 0, sizeof vis);
        return dfs(0, n-1, 0);
    }
};
