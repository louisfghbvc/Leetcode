class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        // interactionCost =>
        // number of edges
        // group => 20
        // group=1
        //         - o
        // o - x - x 
        //          - o - o
        // cost = sum/2

        // consider the contribution
        // (u,v) => cnt[u] * tot - cnt[v]

        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        array<int, 21> tot{};
        for (int x: group) tot[x]++;

        long ans = 0;
        auto dfs = [&](auto&& self, int u, int p = -1) -> array<int, 21> {
            array<int, 21> ret{};
            for (int v: tree[u]) if (v != p) {
                // (u,v)
                auto ch = self(self, v, u);
                for (int i = 0; i < 21; ++i) {
                    ans += 1LL * ch[i] * 1LL * (tot[i] - ch[i]);
                    ret[i] += ch[i]; // accumulate child
                }
            }
            ret[group[u]]++;
            return ret;
        };
        dfs(dfs, 0);
        return ans;
    }
};
