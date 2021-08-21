// Dp + Dijkstra. Careful.

class Solution {
public:
    const long mod = 1e9+7;
    typedef pair<long, long> ii;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<ii>> g(n);
        for(auto &r: roads){
            long u = r[0], v = r[1], w = r[2];
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        
        vector<long> dp(n, LLONG_MAX/2); // dis
        dp[0] = 0;
        
        vector<long> dp2(n); // num of way
        dp2[0] = 1;
        
        priority_queue<ii, vector<ii>, greater<ii>> pq; // dist, u
        pq.push({0, 0});
        
        while(pq.size()){
            auto [cost, u] = pq.top(); pq.pop();
            if(cost > dp[u]) continue; // careful this, prune.
            
            for(auto &[v, w]: g[u]){
                if(dp[v] > cost + w){ // should use cost. since if u doesn't have above if. dp[u] can change and get wrong
                    dp[v] = cost + w;
                    dp2[v] = dp2[u];
                    pq.push({dp[v], v});
                }
                else if(dp[v] == cost + w){
                    dp2[v] = (dp2[v] + dp2[u]) % mod;
                }
            }
        }
        
        return dp2[n-1];
    }
};
