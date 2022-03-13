class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        // calcuate the shortest path 
        // src1->dest + src2->dest - commmon
        // src1->src2->dest or src2->src1->dest
        // general -> src1->node + src2->node + node->dest
        
        // build graph
        // do 3 dijkstra
        // enumerate the bottleneck node
        
        vector<vector<pair<int, int>>> graph(n); // u -> [v, cost]
        vector<vector<pair<int, int>>> rev_graph(n);
        for(auto &e: edges){
            int from = e[0], to = e[1], weight = e[2];
            graph[from].push_back({to, weight});
            rev_graph[to].push_back({from, weight});
        }
        
        auto dijkstra = [&](int s, vector<vector<pair<int, int>>> &g){
            vector<long> dis(n, 1e10);
            dis[s] = 0;
            
            priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq; // min-heap
            pq.push({0, s});
            
            while(pq.size()){
                auto [cost, u] = pq.top(); pq.pop();
                if(dis[u] < cost) continue;
                for(auto &[v, w]: g[u]){
                    if(dis[v] > (long)cost + w){
                        dis[v] = (long)cost + w;
                        pq.push({dis[v], v});
                    }
                }
            }
            return dis;
        };
        
        auto d1 = dijkstra(src1, graph);
        auto d2 = dijkstra(src2, graph);
        auto d3 = dijkstra(dest, rev_graph);
        
        long ans = 1e10;
        for(int i = 0; i < n; ++i)
            ans = min(d1[i] + d2[i] + d3[i], ans);
        return ans >= 1e10 ? -1 : ans;
    }
};
