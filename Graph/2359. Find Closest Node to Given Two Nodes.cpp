class Solution {
public:
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // goal: minimize the maximum of node such that the distance reach node1, node2
        // idea:
        // build the graph, and do bfs, from node1 and node2
        // for each node enumerate the node that distance is smallest
        
        int n = edges.size();
        
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i)
            if (edges[i] != -1)
                graph[i].push_back(edges[i]);
        
        auto bfs = [&](int u) {
            vector<int> dis(n, 1e9);
            vector<bool> vis(n);
            
            queue<pair<int, int>> q; // dis, u
            q.push({0, u});
            vis[u] = 1;
            dis[u] = 0;
            
            while (q.size()) {
                auto [d, u] = q.front(); q.pop();
                for (int v: graph[u]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        dis[v] = d+1;
                        q.push({d+1, v});
                    }
                }
            }
            
            return dis;
        };
        
        auto n1 = bfs(node1);
        auto n2 = bfs(node2);
        
        int dis = 1e9;
        int mn_i = -1;
        for (int i = 0; i < n; ++i) {
            // cout << i << " " << n1[i] << " " << n2[i] << "\n";
            int mx = max(n1[i], n2[i]);
            if (mx < dis) {
                dis = mx;
                mn_i = i;
            }
        }
        
        return mn_i;
    }
};


// node need to build the graph
// O(N)
class Solution {
public:
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // goal: minimize the maximum of node such that the distance reach node1, node2
        // idea:
        // build the graph, and do bfs, from node1 and node2
        // for each node enumerate the node that distance is smallest
        
        int n = edges.size();
        
        auto bfs = [&](int u) {
            vector<int> dis(n, 1e9);
            int stamp = 0;            
            for (int v = u; v != -1 && dis[v] == 1e9; v = edges[v]) {
                dis[v] = stamp++;
            }
            return dis;
        };
        
        auto n1 = bfs(node1);
        auto n2 = bfs(node2);
        
        int dis = 1e9;
        int mn_i = -1;
        for (int i = 0; i < n; ++i) {
            int mx = max(n1[i], n2[i]);
            if (mx < dis) {
                dis = mx;
                mn_i = i;
            }
        }
        
        return mn_i;
    }
};
