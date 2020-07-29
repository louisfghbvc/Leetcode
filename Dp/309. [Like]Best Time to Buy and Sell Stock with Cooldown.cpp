// O(N^2). Straight Forward.
// each i find maximum j. because cooldown so can be from dp[j-2] or 0.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        vector<int> dp(n);
        for(int i = 1; i < n; ++i){
            if(i == 1) dp[i] = max(0, prices[i]-prices[i-1]);
            else{
                dp[i] = dp[i-1];
                for(int j = 0; j < i; ++j){
                    int prev = j >= 2 ? dp[j-2] : 0;
                    dp[i] = max(dp[i], prev + prices[i]-prices[j]);
                }
            }
        }
        return dp[n-1];
    }
};

// O(N). 4ms. Optimal. duplicate (prev - prices[j]).
// just need max so, can use a value... cool...
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        vector<int> dp(n);
        int maxd = -prices[0];
        for(int i = 1; i < n; ++i){
            if(i < 2) maxd = max(maxd, -prices[i]);
            if(i == 1) dp[i] = max(0, prices[i]-prices[i-1]);
            else{
                dp[i] = max(dp[i-1], prices[i] + maxd);
                maxd = max(maxd, dp[i-2] - prices[i]);
            }
        }
        return dp[n-1];
    }
};

// Space Optimal... O(1). divide two part buy and sell.
// Like Fib. Wonderful! Very Nice. Best.
// So b0, b1 is buy[i], buy[i-1]
// s0, s1, s2 is sell[i], sell[i-1], sell[i-2].
// so buy[i] can be from buy[i-1](not buy i), or can be sell[i-2] - price[i] --> because cooldown, and buy i
// sell[i] can be from sell[i-1] and buy[i-1] + price[i] --> prev day buy and cur day sell.
// finallay. sell[i] is ans

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int b0 = -prices[0], b1 = b0;
        int s0 = 0, s1 = 0, s2 = 0;
        for(int i = 1; i < n; ++i){
            b0 = max(b1, s2 - prices[i]);
            s0 = max(s1, b1 + prices[i]);
            b1 = b0; s2 = s1; s1 = s0;
        }
        return s0;
    }
};
