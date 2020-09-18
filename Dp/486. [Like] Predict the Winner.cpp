// Just like stone game.
// O(N^2). max self, minimum other.

class Solution {
public:
    int dp[25][25];
    vector<int> arr;
    int dfs(int l, int r){
        if(l > r) return 0;
        if(dp[l][r]) return dp[l][r];
        int res = max(arr[l] - dfs(l+1, r), arr[r] - dfs(l, r-1));
        return dp[l][r] = res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        arr = nums;
        return dfs(0, nums.size()-1) >= 0;
    }
};
