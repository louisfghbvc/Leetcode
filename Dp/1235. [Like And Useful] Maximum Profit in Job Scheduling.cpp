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


// Concise. use map O(NlogN). so sort by endtime.
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> id;
        for(int i = 0; i < startTime.size(); ++i) id.push_back(i);
        sort(id.begin(), id.end(),[&](int a, int b){
            return endTime[a] < endTime[b];
        });
        
        map<int, int> dp;
        dp[0] = 0;
        for(int i: id){
            auto it = dp.upper_bound(startTime[i]);
            it--;
            int p = it->second + profit[i];
            if (dp.rbegin()->second < p) {
                dp[endTime[i]] = p;
            }
        }
        return dp.rbegin()->second;
    }
};
