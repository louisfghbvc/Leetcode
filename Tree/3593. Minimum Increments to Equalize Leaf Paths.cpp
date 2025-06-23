class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        // problem:
        // edges n-1
        // find the minimum increase nodes number to make root to leaf path scpres equal
        // score: sum of the cost along the path
        // we can increase non-negtive amount

        // input:
        // n=3, [[0,1],[0,2]] [2,1,3]
        // output = 1

        // idea:
        // non-negative amount => means maximum no decrease
        //       1
        //  /        |
        // 2(2)      3
        // / \       / 
        // 4() 5(2)     6

        //       0
        //  /        |
        //  0        0
        // / \       / 
        // 3 2       0

        //       2
        //  /        |
        //  2        2
        // / \           / 
        // 3(x) 2(x)       0

        // minimum nodes
        // build the tree
        // find the maximum sum => change the cost to the need value in the leaf
        // all leaf node is needed => we can extract into the current, and the minimum value will be erase (total count-1)
        // post order

        // code:
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // find maximum path sum
        long mx = 0;
        auto dfs = [&](auto &self, int u, int p=-1, long sum=0) -> void {
            sum += cost[u];
            // leaf
            if (p != -1 && tree[u].size() == 1) {
                mx = max(mx, sum);
                return;
            }
            for (int v: tree[u]) if (p != v) {
                self(self, v, u, sum);
            }
        };
        dfs(dfs, 0);

        vector<long> need(n, 0);
        int ans = 0;
        auto build = [&](auto &self, int u, int p=-1, long sum=0) -> void {
            sum += cost[u];
            // leaf
            if (p != -1 && tree[u].size() == 1) {
                need[u] = mx - sum;
                if (need[u])
                    ans++; // change
                return;
            }
            for (int v: tree[u]) if (p != v) {
                self(self, v, u, sum);
            }
        };
        build(build, 0);

        auto compute = [&](auto &self, int u, int p=-1) -> int {
            if (p != -1 && tree[u].size() == 1) {
                return need[u];
            }

            vector<long> child;
            for (int v: tree[u]) if (p != v) {
                child.push_back(self(self, v, u));
            }
            long mn = ranges::min(child);
            if (mn != 0) {
                int num = count(child.begin(), child.end(), mn);
                // merge into parent
                ans -= num-1;
            }
            return mn;
        };
        compute(compute, 0);

        return ans;
    }
};
