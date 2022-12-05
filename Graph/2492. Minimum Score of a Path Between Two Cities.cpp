// TC: O(nloge)

class Solution {
public:
    
    typedef pair<int, int> ii;
    
    int minScore(int n, vector<vector<int>>& roads) {
        // goal: find the min score, score is min value of the path
        // idea: use dijkstra algorithm to find the shortest path
        
        // build graph
        vector<vector<ii>> graph(n);
        for (auto &edge: roads) {
            graph[edge[0]-1].push_back({edge[1]-1, edge[2]});
            graph[edge[1]-1].push_back({edge[0]-1, edge[2]});
        }
        
        priority_queue<ii, vector<ii>, greater<>> minHeap; // cost, node
        vector<int> dis(n, 1e9);
        
        minHeap.push({1e9, 0});
        while (minHeap.size()) {
            auto [cost, u] = minHeap.top(); minHeap.pop();
            for (auto &[v, w]: graph[u]) {
                int mn = min(cost, w);
                if (mn < dis[v]) {
                    dis[v] = mn;
                    minHeap.push({mn, v});
                }
            }
        }
        
        return dis[n-1];
    }
};

// Solution2: use union find 
// Solution3: just find the connected node to 1
