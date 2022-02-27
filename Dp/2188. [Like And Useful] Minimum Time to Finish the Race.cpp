// a little math, observe
// tricky dp, try to divide to sub-problem

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        // pre-calulate the minimum laps
        
        vector<long> mn(19, INT_MAX);
        mn[0] = 0;
        for(auto &t: tires){
            long f = t[0], r = t[1];
            long x = 0;
            for(int i = 1; i < 19; ++i){
                x += f;
                mn[i] = min(mn[i], x);
                f *= r;
                if(t[0] + changeTime <= f) break; // change will always better
            }
        }
        
        // dp[i]: minimum time do i lap
        // e.g: dp[3] = do 3 times -> mn[3] or dp[1] + ch + dp[2]
        
        vector<long> dp(numLaps+1, INT_MAX);
        for(int i = 1; i <= numLaps; ++i){
            if(i <= 18) dp[i] = mn[i];
            for(int j = 1; j <= i/2; ++j)
                dp[i] = min(dp[i], dp[j] + changeTime + dp[i - j]);
        }
        
        return dp.back();
    }
};
