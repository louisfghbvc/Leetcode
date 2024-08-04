class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        // goal: find the time taken by enumerate each from node i
        
        // idea:
        // enumerate from each nodes -> TC: O(n^2)
        // each time we just traverse neighbor
        // think reroot the tree
        // we need to compute each tree what is the maximum time we cost 

        // when reroot, we need to also update the dp[v] for maximum
        // since u is become a possible subtree of v
        
        int n = edges.size()+1;
        
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
        using T = pair<int, int>;
        vector<array<T, 2>> dp(n); // each node, need to record top 2 maximum

        auto upd = [&](auto &rec, const auto& val) -> void {
            if (val.first >= rec[0].first) {
                rec[1] = rec[0];
                rec[0] = val;
            }
            else if (val.first >= rec[1].first) {
                rec[1] = val;
            }
        };

        auto dfs = [&](auto &self, int u, int p = -1) -> int {
            int ans = 0;
            array<T, 2> rec;
            rec[1] = rec[0] = {0, -1};
            for (int v: tree[u]) if (v != p) {
                int mx = self(self, v, u);
                if (v % 2 == 0) mx += 2;
                else mx += 1;
                upd(rec, make_pair(mx, v));
            }
            
            dp[u] = rec;
            return rec[0].first;
        };
        
        vector<int> ans(n);
        ans[0] = dfs(dfs, 0);
        
        auto dfs2 = [&](auto &self, int u, int p=-1) -> void {
            for (int v: tree[u]) if (v != p) {
                if (dp[u][0].second == v) {
                    ans[v] = ans[u] - dp[u][0].first + dp[u][1].first;
                    auto tmp = dp[u][1];
                    if (u % 2 == 0) ans[v] += 2, tmp.first += 2;
                    else ans[v]++, tmp.first++;
                    upd(dp[v], tmp);
                    ans[v] = max(ans[v], dp[v][0].first);
                }
                else {
                    ans[v] = ans[u];
                    auto tmp = dp[u][0];
                    if (u % 2 == 0) ans[v] += 2, tmp.first += 2;
                    else ans[v]++, tmp.first++;
                    upd(dp[v], tmp);
                    ans[v] = max(ans[v], dp[v][0].first);
                }
            }

            for (int v: tree[u]) if (v != p) {
                self(self, v, u);
            }
        };
        
        dfs2(dfs2, 0);
        return ans;
    }
};
