//Can sell then sell. Get price.
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
