// O(D). Easy to think.
// if not in days, no need to pay money.
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        bool vis[366] = {};
        int dp[366] = {};
        for(int &d: days){
            vis[d] = 1;
        }
        for(int i = 1; i <= 365; ++i){
            if(!vis[i]) dp[i] = dp[i-1];
            else{
                int mn = INT_MAX;
                mn = min(dp[i-1] + costs[0], mn);
                mn = min(dp[max(0, i-7)] + costs[1], mn);
                mn = min(dp[max(0, i-30)] + costs[2], mn);
                dp[i] = mn;
            }
        }
        return dp[days.back()];
    }
};
