// Just dijkstra. O(ElogE)
// Can also use BFS. because no need to sort. BFS more faster

class Solution {
typedef pair<double, int> di;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<di> g[n];
        for(int i = 0; i < edges.size(); ++i){
            int a = edges[i][0], b = edges[i][1];
            double w = succProb[i];
            g[a].push_back({w, b});
            g[b].push_back({w, a});
        }
        
        priority_queue<di> pq;
        vector<double> d(n, 0.0);
        d[start] = 1.0;
        pq.push({1.0, start});
        while(pq.size()){
            di tmp = pq.top(); pq.pop();
            int u = tmp.second; double c = tmp.first;
            for(auto &nt: g[u]){
                int v = nt.second; double w = nt.first;
                if(d[u]*w > d[v]){
                    d[v] = d[u]*w;
                    pq.push({d[u]*w, v});
                }
            }
        }
        return d[end];
    }
};
