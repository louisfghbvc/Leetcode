class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        // goal: find the nubmer of root tree such that the guesses is at least k
        // idea:
        // fix the root from 0, try to move adjacent to check if guesses sucess
        // guess -> hashmap
        // edges -> build tree
        // ans can get from parent
        
        int n = 1+edges.size();
        vector<vector<int>> tree(n);
        vector<unordered_set<int>> mp(n);
        
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        for (auto &e: guesses) {
            int u = e[0], v = e[1];
            mp[u].insert(v);
        }
        
        vector<int> dp(n);
        // dfs1
        auto dfs1 = [&](auto &self, int u, int p=-1) -> void {
            for (int v: tree[u]) if (v != p) {
                if (mp[u].count(v)) dp[0]++;
                self(self, v, u);
            }
        };
        dfs1(dfs1, 0); // get dp
        
        // build from root
        auto dfs = [&](auto &self, int u, int p=-1) -> void {
            for (int v: tree[u]) if (v != p) {
                dp[v] = dp[u] - mp[u].count(v) + mp[v].count(u);
                self(self, v, u);
            }
        };
        dfs(dfs, 0);
        
        // get ans
        int ans = 0;
        for (int x: dp)
            ans += x >= k;
        return ans;
    }
};
