class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // goal: for each node find the minimum reverse to reach every node

        // idea:
        // brute force -> each node dfs -> too slow
        //    a
        //  b    c
        //   d
        // fix the root -> calculate the inverse count
        // build the tree with cost
        // u -> v, 0
        // v -> u, 1
        
        vector<vector<pair<int, int>>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].emplace_back(e[1], 0);
            tree[e[1]].emplace_back(e[0], 1);
        }

        vector<int> res(n);
        auto dfs = [&](auto &self, int u, int p=-1) -> void {
            for (auto &[v, c]: tree[u]) if (v != p) {
                res[0] += c;
                self(self, v, u);
            }
        };
        dfs(dfs, 0);

        auto dfs2 = [&](auto &self, int u, int p=-1) -> void {
            for (auto &[v, c]: tree[u]) if (v != p) {
                res[v] = res[u] + (c == 0 ? 1 : -1);
                self(self, v, u);
            }
        };
        dfs2(dfs2, 0);

        return res;
    }
};
