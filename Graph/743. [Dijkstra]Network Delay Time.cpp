typedef pair<int, int> pr;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> d(N + 5, 1e7);
        vector<pr> g[N + 5];
        bool vis[N + 5] = {};
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        d[K] = 0;
        for(const auto e : times){
            g[e[0]].push_back({e[2], e[1]});
        }
        pq.push({0, K});
        while(!pq.empty()){
            pr cur = pq.top(); pq.pop();
            int u = cur.second;
            if(vis[u]) continue;
            vis[u] = true;   
            for(int i = 0; i < g[u].size(); ++i){
                pr to = g[u][i];
                int v = to.second, w = to.first;
                if(!vis[v] && d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
        bool ok = true;
        int mx = 0;
        for(int i = 1; i <= N; ++i){
            if(i == K) continue;
            if(d[i] == 1e7){
                ok = false;
                break;
            }
            mx = max(d[i], mx);
        }
        
        return ok ? mx : -1;
    }
};
