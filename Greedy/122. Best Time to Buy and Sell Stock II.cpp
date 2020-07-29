// Autually is because the big diff always not > small diff
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cash = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1]){
                cash += prices[i]-prices[i-1];
            }
        }
        return cash;
    }
};

// O(N) dp, same as cooldown.
// always get maximum. like fib.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b0 = -prices[0], b1 = b0;
        int s0 = 0, s1 = 0;
        for(int i = 1; i < prices.size(); ++i){
            b0 = max(b1, s1 - prices[i]);
            s0 = max(s1, b1 + prices[i]);
            b1 = b0, s1 = s0;
        }
        return s0;
    }
};
