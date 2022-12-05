class Solution {
public:
    
    vector<int> p;
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {
        // goal: find the maximum group, such that edge group index abs distance is 1
        // idea: 
        // determine the impossible case: if a node come from same group of far distance group
        // for each connect component, find the max group, sum of them -> use union find
        // max group use bfs to level order them
        // bfs should start from minimum indegree node, find all min indegree
        
        
        p = vector<int>(n, -1);
        
        vector<vector<int>> graph(n);
        vector<int> ind(n);
        for (auto &e: edges) {
            e[0]--, e[1]--;
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            uni(e[1], e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }
        
        int ans = 0;
        vector<vector<int>> group(n);
        for (int i = 0; i < n; ++i)
            group[find(i)].push_back(i);
        
        for (auto &g: group) {
            if (g.empty()) continue;
            // find the start point
            int min_degree = n;
            vector<int> can = {g[0]};
            for (int x: g) {
                if (ind[x] < min_degree) {
                    min_degree = ind[x];
                    can = {x};
                }
                else if (ind[x] <= min_degree)
                    can.push_back(x);
            }
            
            // do bfs
            int best = 1;
            for (int start: can) {
                queue<pair<int, int>> q; // node, dis
                unordered_map<int, int> dis;
                q.push({start, 1});
                dis[start] = 1;
                int cur = 1;
                while (q.size()) {
                    auto [u, d] = q.front(); q.pop();
                    if (dis.count(u) && dis[u] != d) continue;
                    for (int v: graph[u]) {
                        if (dis.count(v)) {
                            if (dis[v] != d+1 && dis[v] != d-1)
                                return -1;
                        }
                        else {
                            dis[v] = d+1;
                            cur = max(cur, d+1);
                            q.push({v, d+1});
                        }
                    } 
                }
                best = max(best, cur);
            }
            ans += best;
        }
        
        return ans;
    }
};
