// Graph + dp
// dijkstra. 

class Solution {
public:
    const int mod = 1e9+7;
    typedef pair<int, int> ii;
    
    vector<int> cnt;
    vector<int> dis;
    vector<vector<ii>> g;
    int dfs(int u, int p){
        if(cnt[u] != -1) return cnt[u];
        long res = 0;
        for(auto &[w, v] : g[u]){
            if(v != p && dis[u] > dis[v]){
                res += dfs(v, u);
            }
        }
        return cnt[u] = res % mod;
    }
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        g = vector<vector<ii>>(n+1);
        for(auto &e: edges){
            g[e[0]].push_back({e[2], e[1]});    
            g[e[1]].push_back({e[2], e[0]});   
        }
        
        dis = vector<int>(n+1, 2e9);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, n});
        while(pq.size()){
            auto [d, u] = pq.top(); pq.pop();
            if(dis[u] < d) continue;
            dis[u] = d;
            for(auto &[w, v]: g[u]){
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }
        
        cnt = vector<int>(n+1, -1);
        cnt[n] = 1;
        return dfs(1, -1);
    }
};
