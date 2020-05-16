// bottom-up 01 unbound bag. and greedy. big to small.
// classic and some change.
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target+1, "");
        vector<bool> ok(target+1, 0);
        ok[0] = 1;
        for(int i = 8; i >= 0; --i){
            for(int w = cost[i]; w <= target; ++w){
                ok[w] = ok[w] | ok[w-cost[i]];
                if(!ok[w]) continue;
                int l = dp[w-cost[i]].size()+1;
                if(l > dp[w].size()){
                    dp[w] = dp[w-cost[i]] + to_string(i+1);
                }
                else if(l == dp[w].size()){
                    dp[w] = max(dp[w], dp[w-cost[i]] + to_string(i+1));
                }
            }
        }
        return ok[target] ? dp[target] : "0";
    }
};
