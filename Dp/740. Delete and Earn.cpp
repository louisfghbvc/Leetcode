// like knapsack. O(MX).

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> fre;
        
        int mx = 0;
        for(int x: nums){
            fre[x]++;
            mx = max(x, mx);
        }
        
        // dp[i] is maximum val from mn to i
        // dp[i] = max(dp[i-1], dp[i-2] + i * fre[i]);
        vector<int> dp(mx+1);
        dp[1] = fre[1]; // edge case
        for(int i = 2; i <= mx; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + i * fre[i]);
        }
            
        return *max_element(dp.begin(), dp.end());
    }
};
