// OK. O(N^2). Intuition. just like classic lis.
// and use addtional array to cache len.
// find max lis length.
// remember to sum all longest length up
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        
        int dp[n];
        int cnt[n];
        
        int mx = 0;
        for(int i = 0; i < n; ++i){
            dp[i] = cnt[i] = 1;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[j]+1 == dp[i]) cnt[i] += cnt[j];
            }
            if(mx < dp[i]) mx = dp[i];
        }
        
        int res = 0;
        for(int i = 0; i < n; ++i) if(mx == dp[i]) res += cnt[i];
        
        return res;
    }
};
