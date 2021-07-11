// O(T*E). Simple. just traverse all time. and update the dp
class Solution {
public:    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        vector<vector<int>> dp(n, vector<int>(maxTime+1, 1e9));
        
        dp[0][0] = fees[0];
        for(int i = 0; i <= maxTime; ++i){
            for(auto &e: edges){
                int u = e[0], v = e[1], t = e[2];
                if(i + t > maxTime) continue;
                if(dp[v][i + e[2]] > dp[u][i] + fees[v]){
                    dp[v][i + e[2]] = dp[u][i] + fees[v];
                }
                if(dp[u][i + e[2]] > dp[v][i] + fees[u]){
                    dp[u][i + e[2]] = dp[v][i] + fees[u];
                }
            }
        }
        
        int res = 1e9;
        for(int i = 0; i <= maxTime; ++i)
            res = min(res, dp[n-1][i]);
        
        return res == 1e9 ? -1 : res;
    }
};

// O(ElogE?). intersting. so use non-optimal answer into queue.
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n = fees.size();
        vector<vector<pair<int, int>>> g(n);
        
        for(auto &e: edges){
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({fees[0], 0, 0}); // fees, time, cur node
        
        vector<int> dp(n, 1e9), dp2(n, 1e9); // dp: cost, dp2: time
        dp[0] = fees[0];
        dp2[0] = 0;
        
        while(pq.size()){
            auto cur = pq.top(); pq.pop();
            int f = cur[0], t = cur[1], u = cur[2];
            for(auto &[v, vt]: g[u]){
                if(t + vt <= maxTime){
                    if(dp[v] > f + fees[v]){ // cost less, not use dp
                        dp[v] = f + fees[v];
                        dp2[v] = t + vt;
                        pq.push({dp[v], dp2[v], v});
                    }
                    else if(dp2[v] > t + vt){ // time less, not use dp2
                        dp2[v] = t + vt;
                        pq.push({f + fees[v], dp2[v], v});
                    }
                }
            }
        }
        
        return dp[n-1] >= 1e9 ? -1 : dp[n-1];
    }
};
