// Just dijkstra. O(ElogE)
// Can also use BFS. because no need to sort. BFS more faster

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // goal: find the maximum probability
        // idea:
        // build graph + dijkstra

        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int a = edges[i][0], b = edges[i][1];
            graph[a].emplace_back(b, succProb[i]);
            graph[b].emplace_back(a, succProb[i]);
        }

        vector<double> dp(n, 0);
        dp[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        while (pq.size()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (dp[u] != cost) continue;
            for (auto &[v, w]: graph[u]) {
                if (dp[v] == 0 || cost * w > dp[v]) {
                    dp[v] = cost*w;
                    pq.push({cost*w, v});
                }
            }
        }

        return dp[end_node];
    }
};
