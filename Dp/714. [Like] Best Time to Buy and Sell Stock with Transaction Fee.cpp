// Solution1 T:O(N). S:O(N)
// 4 case. buy or not buy, sell or not sell.
// remember sell never be negative.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        vector<int> buy(n), sell(n);
        for(int i = 0; i < n; ++i){
            // buy
            buy[i] = -prices[i];
            if(i) buy[i] = max(buy[i], sell[i-1] - prices[i]);
            // not buy
            if(i) buy[i] = max(buy[i], buy[i-1]);
            // sell, if neg not sell
            sell[i] = max(0, prices[i] - fee + buy[i]);
            // not sell
            if(i) sell[i] = max(sell[i], sell[i-1]);
        }
        return sell.back();
    }
};

// O(1) Space.
