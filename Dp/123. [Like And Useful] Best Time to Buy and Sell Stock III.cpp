// O(N). O(1).
// hard to think to use state machine. learn a lot.
// use state machine... awesome. 
// very different.
// so s0 is start. s0->s1. need to buy or not buy.
// s1->s2 need to sell or not sell. same as s3, s4.
// finally s4

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int s1 = -prices[0], s2 = 0, s3 = INT_MIN, s4 = 0;
        for(int i = 1; i < n; ++i){
            s1 = max(s1, -prices[i]);
            s2 = max(s2, s1+prices[i]);
            s3 = max(s3, s2-prices[i]);
            s4 = max(s4, s3+prices[i]);
        }
        return s4;
    }
};

// Dp.
// dp[k][i] = max(dp[k][i-1], price[i] - price[j] + dp[k-1][j-1]) j = 0~i-1
// O(kN)
// and  -price[j] + dp[k-1][j-1] =  -(price[j] - dp[k-1][j-1]), so try to minimum (price[j] - dp[k-1][j-1])
// remove loop. trick.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int dp[3][n+1];
        memset(dp, 0, sizeof dp);
        
        for(int k = 1; k <= 2; ++k){
            int mn = prices[0];
            for(int i = 1; i < n; ++i){
                mn = min(mn, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - mn);
            }   
        }
        
        return dp[2][n-1];
    }
};
