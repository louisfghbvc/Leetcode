// O(NS). Tweak about bag.
// so the key point each value have 3 choice, can be multiply 0, -1, +1
// dp[j] means to get j, maximum positive sum.
// so dp[j] from prev dp[j] or prev dp[j-v] + v or prev dp[j+v], why is not dp[j+v] - v, because -v isn't a best choose.
// dp[j] is maximum positive sum to get value j. so no need to -v.
// so, understand ?
// the magic of power dp...
// and make - to +, add sum.

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int sum = accumulate(rods.begin(), rods.end(), 0);
        int ps = 2 * sum;
        vector<int> dp(ps+1, -1);
        dp[sum] = 0;
        for(int i = 0; i < n; ++i){
            vector<int> tmp = dp;
            for(int j = 0; j <= ps; ++j){
                if(j >= rods[i] && dp[j - rods[i]] != -1){
                    tmp[j] = max(tmp[j], dp[j - rods[i]] + rods[i]);
                }
                if(j + rods[i] <= ps && dp[j + rods[i]] != -1){
                    tmp[j] = max(tmp[j], dp[j + rods[i]]);
                }
            }
            dp = tmp;
        }
        return dp[sum];
    }
};
