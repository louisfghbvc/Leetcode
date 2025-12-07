class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        // goal:
        // score : good nodes - bad nodes
        // ans[i]: maximum score of node i

        // idea:
        // from each node as root => easy to compute
        // reroot node?
        // bad[i] = treesize[i]-good[i]
        
        //    1      
        //  2. 3
        // 4 
        //.   2(1)
        //   4 1(1)
        //      3(1)

        //   1
        //  2 3
        // 4      => above size[i] = n - treesize, above good nodes

        //       1(1)(3)
        //  2(0)m=1   3(0)m=1
        // 4(1)     5 (1)

        //        1(1)(3)
        //  2(0)m=0   3(0)m=1
        // 4(0)          5 (1)

        // reroot
        // child v has one more contribute

        // root 0

        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> ans(n);
        vector<int> dp(n);
        auto dfs1 = [&](auto&self, int u=0, int p=-1) -> int {
            int sum = 0;
            for (int v: tree[u]) if (v != p) {
                // no choose, choose
                sum += max(0, self(self, v, u));
            };
            return dp[u] = sum + (good[u]?1:-1);
        };
        ans[0] = dfs1(dfs1);

        auto dfs2 = [&](auto& self, int u=0, int p=-1) -> void {
            for (int v: tree[u]) if (v != p) {
                int parent_dp = ans[u] - max(0, dp[v]);
                ans[v] = dp[v] + max(0, parent_dp);
                self(self, v, u);
            };
        };
        dfs2(dfs2);

        return ans;
    }
};
