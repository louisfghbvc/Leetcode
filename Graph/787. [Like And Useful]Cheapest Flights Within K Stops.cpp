// dijkstra algorithm, use tuple.
// so cost and cur node and stop.
// stop == 0 means can not move and get minimum.
// O(NElogE) 88ms. 12.4MB
typedef tuple<int,int,int> tp;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int g[105][105] = {};
        for(const auto &e: flights){
            g[e[0]][e[1]] = e[2];
        } 
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.push({0, src, K+1});
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int u = get<1>(cur), cost = get<0>(cur), stop = get<2>(cur);
            if(u == dst) return cost;
            if(!stop) continue;
            for(int v = 0; v < n; ++v){
                if(g[u][v]){
                    pq.push({g[u][v]+cost, v, stop-1});
                }
            }
        }
        return -1;
    }
};

// BFS + prune. 28ms. fast O(N^3)
// remember to prune to speed up, so many no use state same as dfs.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int g[105][105] = {};
        for(const auto &e: flights){
            g[e[0]][e[1]] = e[2];
        }
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        int dep = 0, mn = 1e9;
        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s; ++i){
                auto cur = q.front(); q.pop();
                int u = cur.first, c = cur.second;
                if(u == dst) mn = min(mn, c);
                // printf("%d %d\n", u, c);
                for(int v = 0; v < n; ++v){
                    if(g[u][v]){
                        if(c+g[u][v] > mn) continue; 
                        q.push({v, c+g[u][v]});
                    }
                }
            }
            if(dep++ > K) break;
        }
        return mn == 1e9 ? -1 : mn;
    }
};

// Amazing solution bellmon ford.
// Learn it impressive. O(KE). dymanic programming. relax k times
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dp(n, 1e9);
        dp[src] = 0;
        for(int k = 0; k <= K; ++k){
            vector<int> c = dp;
            for(const auto&e: flights){
                c[e[1]] = min(c[e[1]], dp[e[0]] + e[2]);
            }            
            dp = c;
        }
        return dp[dst] == 1e9 ? -1 : dp[dst];
    }
};
