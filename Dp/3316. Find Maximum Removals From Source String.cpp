class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        // goal: find the maximum remove such that pattern is sub of source

        // idea:
        // "abc", "ab"
        // [0,1] 
        // ans = 0

        // indices is no order => bool array
        // consider dp
        // dp[i][j]: maximum remove starting from index i
        // dp[i][j]: each index can erase or not

        int n = source.size();
        int m = pattern.size();
        vector dp(n, vector(m+1, -1));
        vector<bool> vis(n);
        for (int x: targetIndices)
            vis[x] = true;

        auto dfs = [&](auto &self, int i, int j) -> int {
            if (i >= n) return j == m ? 0 : -1e5;

            int &res = dp[i][j];
            if (res != -1) return res;

            // skip i, no match
            res = self(self, i+1, j);
            if (j < m && source[i] == pattern[j])
                res = max(res, self(self, i+1, j+1));

            if (vis[i]) {
                res = max(res, 1 + self(self, i+1, j));
            }

            return res;
        };

        return dfs(dfs, 0, 0);
    }
};
