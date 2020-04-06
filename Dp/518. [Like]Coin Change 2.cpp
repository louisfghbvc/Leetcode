//from not put and (put it, put coin[i] must subtract coin[i])
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); ++i){
            for(int w = coins[i]; w <= amount; ++w){
                dp[w] = dp[w] + dp[w-coins[i]];
            }
        }
        return dp[amount];
    }
};
