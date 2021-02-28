// Use dp. like 01 bag.

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n = baseCosts.size();
        int m = toppingCosts.size();
        
        int tot = 2e4+1;
        int close = 1e9;
        for(int base: baseCosts){
            vector<bool> dp(tot);
            dp[base] = 1;
            for(int top: toppingCosts){
                for(int w = tot-1; w >= top; --w){
                    if(w >= 2*top) dp[w] = dp[w] | dp[w-2*top];
                    dp[w] = dp[w] | dp[w-top];
                }
            }
            for(int i = tot; i >= 0; --i){
                if(dp[i]){
                    if(abs(close - target) > abs(i - target)){
                        close = i;
                    }
                    else if(abs(close - target) == abs(i - target) && i < close) close = i;
                }
            }
        }
        
        return close;
    }
};
