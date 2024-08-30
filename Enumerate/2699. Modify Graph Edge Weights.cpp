class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // goal: find the edge such that the shortest path is equal to target

        // idea:
        // 1 -> 2 -> 3
        // o -> o -> o  o  o  o 
        //   4    5   1  1   1
        // consider impossible case:
        // 1. if we fill all weight in 1
        // then we can not reach dest => fail
        // dis[dest] > target => fail
        // 2.
        // dis[dest] == target => done
        // 3. 
        // dis[dest] < target => we need modify the edges
        // we need to do from back
        // enumerate -> try to make edge => inf
        // when we find out we can not get dest => means
        // edge is critical => cost = target - dis[dest]
        // 
        //   o 
        //  1/ \ 1
        // o  o
        // 1\ /1
        //  o

        // too slow => since each time we need to build graph
        // can be better!
        // after looking the solution
        // we can increment the edge one by one
        // 1. when we add the edge and dis <= target => find!
        // 

        using T = pair<long, long>;
        vector<vector<T>> graph(n);
        for (auto &e: edges) {
            if (e[2] == -1) continue;
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        } 

        auto dijkstra = [&](int s, int t) -> vector<int> {
            vector dis(n, -1);
            priority_queue<T,vector<T>,greater<>> pq;
            pq.push({0, source});
            dis[source] = 0;
            while (pq.size()) {
                auto [cost, u] = pq.top(); pq.pop();
                if (cost != dis[u]) continue;
                for (auto &[v, w]: graph[u]) {
                    if (dis[v] == -1 || dis[v] > cost + w) {
                        dis[v] = cost + w;
                        pq.push({dis[v], v});
                    }
                }
            }

            return dis;
        };

        auto dis = dijkstra(source, destination);
        if (dis[destination] != -1 && dis[destination] < target) return {};

        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][2] != -1) continue;
            edges[i][2] = 1;
            graph[edges[i][0]].emplace_back(edges[i][1], 1);
            graph[edges[i][1]].emplace_back(edges[i][0], 1);
            dis = dijkstra(source, destination);
            // find critical
            if (dis[destination] != -1 && dis[destination] <= target) {
                edges[i][2] = 1 + target - dis[destination]; // need to change to good
                for (auto &e: edges)
                    if (e[2] == -1)
                        e[2] = 2e9;
                return edges;
            }
        }

        return dis[destination] == target ? edges : vector<vector<int>>{};
    }
};
