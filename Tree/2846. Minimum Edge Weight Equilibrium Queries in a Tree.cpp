class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        // goal: for each query, minimum operations to make a->b path all weight equal
        
        // 1 <= n <= 10^4
        // edges.size() == n-1
        // 0 <= u,v < n
        // 1 <= w <= 26
        
        // idea:
        // find maximum frequency of path
        // ans[i] = path length - max fre
        // any nodes of path length -> lca
        // fre: fre[a] - fre[lca] + fre[b] - fre[lca]
        // path: dis[a] - dis[lca] + dis[b] - dis[lca]
        
        // build graph
        // calculate the lca
        
        vector<vector<pair<int, int>>> graph(n);
        for (auto &e: edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        int m = log2(n)+1;
        vector par(n, vector(m, 0));
        vector fre(n, array<int,27>{});
        vector dis(n, 0), in(n, 0), out(n, 0);
        
        // 0 as root
        array<int, 27> cnt {};
        int stamp = 0;
        auto dfs = [&](auto &self, int u, int p=-1, int dep=0) -> void {
            in[u] = stamp++;
            dis[u] = dep;
            fre[u] = cnt;
            for (auto &[v, w]: graph[u]) if (v != p) {
                par[v][0] = u;
                cnt[w]++;
                self(self, v, u, dep+1);
                cnt[w]--;
            }
            out[u] = stamp++;
        };
        dfs(dfs, 0);
        
        // compute lca
        for (int p = 1; p < m; ++p) {
            for (int i = 0; i < n; ++i) {
                par[i][p] = par[par[i][p-1]][p-1];
            }
        }
        auto anc = [&](int x, int y) -> bool {
            return in[x] <= in[y] && out[x] >= out[y];
        };
        auto LCA = [&](int x, int y) -> int {
            if (anc(x, y)) return x;
            if (anc(y, x)) return y;

            for (int i = m-1; i >= 0; --i){
                if (!anc(par[x][i], y))
                    x = par[x][i];
            }
            return par[x][0];
        };
        
        vector<int> ans;
        for (auto &q: queries) {
            int a = q[0], b = q[1];
            int lca = LCA(a,b);
            int len = dis[a]+dis[b]-2*dis[lca];
            array<int, 27> cnt {};
            for (int j = 0; j < 27; ++j)
                cnt[j] += fre[a][j] + fre[b][j] - 2*fre[lca][j];
            int mx = *max_element(cnt.begin(), cnt.end());
            ans.push_back(len - mx);
        }
        return ans;
    }
};
