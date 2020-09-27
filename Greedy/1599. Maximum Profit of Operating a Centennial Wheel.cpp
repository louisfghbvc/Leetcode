// tag greedy. but just simulate.
// took a lot of times and WA 1 time...
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0, mx = -1;
        int times = 0, in = 0, ans, i = 0, wait = 0;
        while(wait > 0 || i < customers.size()){
            times++;
            if(i < customers.size()) wait += customers[i];
            profit = (min(4, wait)+in)*boardingCost - times*runningCost;
            if(mx < profit){
                mx = profit;
                ans = times;
            }
            in += min(4, wait);
            wait = max(0, wait-4);
            i++;
        }
        return mx < 0 ? -1 : ans;
    }
};
