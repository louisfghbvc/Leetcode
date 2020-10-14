// O(N). Dp. like Fib but circle. just two case (begin end) can not take both.

class Solution {
public:
    int dp[105];
    int help(vector<int> &nums, int l, int r){
        memset(dp, 0, sizeof dp);
        for(int i = l; i < r; ++i){
            dp[i] = nums[i];
            if(i > 0) dp[i] = max(dp[i], dp[i-1]);
            if(i >= 2) dp[i] = max(dp[i-2]+nums[i], dp[i]);
        }
        return dp[r-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(help(nums, 0, n-1), help(nums, 1, n));
    }
};

// O(N). Space: O(1)
class Solution {
public:
    int help(vector<int> &nums, int l, int r){
        int prev = 0, cur = 0;
        for(int i = l; i < r; ++i){
            int tmp = max(prev+nums[i], cur);
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(help(nums, 0, n-1), help(nums, 1, n));
    }
};
