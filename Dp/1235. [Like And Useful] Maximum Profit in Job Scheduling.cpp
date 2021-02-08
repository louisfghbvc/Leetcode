// preprocess time to continous values. and then process as graph. and just dp.

class Solution {
public:
    typedef pair<int, int> ii;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<int> pos;
        for(int i = 0; i < n; ++i){
            pos.push_back(startTime[i]);
            pos.push_back(endTime[i]);
        }
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        
        int N = pos.size();
        vector<vector<ii>> g(N);
        for(int i = 0; i < n; ++i){
            startTime[i] = lower_bound(pos.begin(), pos.end(), startTime[i]) - pos.begin();
            endTime[i] = lower_bound(pos.begin(), pos.end(), endTime[i]) - pos.begin();
            g[endTime[i]].push_back({startTime[i], profit[i]});
        }
        
        vector<int> dp(N);
        for(int i = 0; i < N; ++i){
            for(auto &[start, val]: g[i])
                dp[i] = max(dp[i], dp[start] + val);
            if(i) dp[i] = max(dp[i], dp[i-1]);
        }
        
        return dp.back();
    }
};
