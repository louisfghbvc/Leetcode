// Classic dp. O(n*amount).

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int x: coins){
            for(int i = x; i <= amount; ++i){
                dp[i] = min(dp[i], dp[i-x]+1);
            }
        }      
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
