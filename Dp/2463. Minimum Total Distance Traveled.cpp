class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // goal: find the minimum total distance to robots
        // such that each robot is caught by a factory

        // idea1:
        // build the graph => do min cost max flow

        // idea2:
        // for each factory we can try to pick n robots
        // consider dp
        // dp[i][j]: minimum distaince using i factory and j robots
        // dp[i][j] => min(dp[i-1][j-1] + dis(), dp[i-1][j-2] + dis())
        // TC: O(n * m * l)

        // sort the robot and factory
        ranges::sort(robot);
        sort(factory.begin(), factory.end(), [&](auto& a, auto& b) {
            return a[0] < b[0];
        });

        int n = factory.size();
        int m = robot.size();
        vector dp(n, vector<long>(m, -1));
        auto dfs = [&](auto &self, int i, int j) -> long {
            if (i >= n) return j == m ? 0 : LLONG_MAX;
            if (j == m) return 0;

            auto& res = dp[i][j];
            if (res != -1) return res;

            // skip ith factory
            res = self(self, i+1, j);

            // used ith factory
            long dis = 0;
            for (int c = 1; c <= factory[i][1] && j < m; ++c) {
                dis += abs(factory[i][0] - robot[j]);
                j++;
                auto next = self(self, i+1, j);
                if (next != LLONG_MAX)
                    res = min(res, dis + next);
            }
            return res;
        };

        return dfs(dfs, 0, 0);
    }
};

// MCMF
class Solution {
public:
    
    template<size_t N, typename C=int, typename W=int>
    struct mcmf {
        struct edge {
            int v, v_id;
            C c; // flow
            W w; // weight
            edge (int v, int v_id, C c, W w) : v(v), v_id(v_id), c(c), w(w) {}
        };

        vector<edge> g[N];
        typename vector<edge>::iterator idx[N];
        int pre[N]; // parent
        W d[N], h[N]; // dis, prime-dual alg
        bool visit[N];
        int n;
        mcmf (int n) : n(n) {}

        void add_edge(int x, int y, C c, W w) {
            g[x].emplace_back(y, g[y].size(), c, w);
            g[y].emplace_back(x, g[x].size() - 1, 0, -w);
        }

        bool dijkstra(int s, int t) {
            priority_queue<pair<W, int>, vector<pair<W, int>>, greater<pair<W, int>>> pq; // weight, u
            fill(pre, pre+n, -1);
            fill(d, d+n, numeric_limits<W>::max() / 2);
            d[s] = 0;
            pq.push({d[s], s});
            while (pq.size()) {
                auto [dd, u] = pq.top(); pq.pop();
                if (d[u] != dd) continue;
                for (auto it = g[u].begin(); it != g[u].end(); ++it) {
                    if (it->c && d[it->v] + h[it->v] > d[u] + it->w + h[u]) {
                        d[it->v] = d[u] + it->w + h[u] - h[it->v]; // note: w + h[u] - h[v] >= 0
                        pre[it->v] = u;
                        idx[it->v] = it;
                        pq.push({d[it->v], it->v});
                    }
                }
            }
            return pre[t] >= 0;
        }

        W solve(int s, int t) { 
            fill(h, h + n, 0);
            W sum = 0;
            int cnt = 0;
            while (dijkstra(s, t)) {
                for (int i = 0; i < n; ++i) h[i] += pre[i] < 0 ? 0 : d[i];
                C aug = 1;
                for (int i = t; pre[i] != -1; i = pre[i]) {
                    idx[i]->c -= aug;
                    g[idx[i]->v][idx[i]->v_id].c += aug;
                    sum += idx[i]->w; 
                }
                cnt++;
            }
            // cout << cnt << "\n";
            return sum;
        }
    };
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // goal: find the minimum total distance, where each fatcory only repair at most limit
        // no care the movement and cross over and time
        // idea1: greedy -> fail 
        // each robot can choose any one factory
        // each factory choose the smallest 
        // step1, build the edge, sort the cost 
        // choose the smallest edge until the size is robot.size
        // skip edge when factory size is limit or used robot
        
        // idea2: min cost flow?
        
        
        // idea3: dp
        
        // sort(robot.begin(), robot.end());
        // sort(factory.begin(), factory.end());
        
        int n = robot.size();
        int m = factory.size();
        
        const int N = 100;
        mcmf<N * 2 + 2, long, long> flow(N * 2 + 2);
        int s = N*2, t = s+1; // dummy node

        for (int i = 0; i < n; ++i) {
            flow.add_edge(s, i, 1, 0);
        }
        for (int i = 0; i < m; ++i) {
            flow.add_edge(n+i, t, factory[i][1], 0);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                flow.add_edge(i, n+j, 1, abs(robot[i] - factory[j][0]));
            }
        }   
        
        return flow.solve(s, t);
    }
};
