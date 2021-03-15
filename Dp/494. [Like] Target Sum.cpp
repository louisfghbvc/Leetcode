// O(N*sum). Space O(N*sum)

class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int> &nums, int i, int cur, int &S){
        if(i == nums.size()){
            return cur == S;
        }
        if(dp[i][cur + 1000] != -1) return dp[i][cur + 1000];
         
        int res = dfs(nums, i+1, cur+nums[i], S);
        res += dfs(nums, i+1, cur-nums[i], S);
        return dp[i][cur + 1000] = res;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        dp = vector<vector<int>> (nums.size(), vector<int>(2001, -1));
        return dfs(nums, 0, 0, S);
    }
};
