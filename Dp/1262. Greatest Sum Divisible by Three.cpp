//92ms 19.9MB
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for(int num : nums){
            vector<int> dp2 = dp;
            for (int i = 0; i < 3; ++i){
                int sum = dp[i] + num;
                dp2[sum % 3] = max(dp2[sum % 3], sum);
            }
            dp = dp2;
        }
        return dp[0];
    }
};
