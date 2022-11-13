class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // amount: even
        // goal: find the maximum profit can reach any leaf node
        // idea: 
        // first, change the amount -> is it easy to implement? yes
        // find the path, and update the node
        
        // TC: O(N), SC:O(N)
        
        int n = amount.size();
        
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
        vector<int> path; // root -> bob only one path 
        auto findPath = [&](auto &self, int u, int p=-1) {
            path.push_back(u);            
            if (u == bob) return true;
            for (int v: tree[u]) if (v != p) {
                if (self(self, v, u))
                    return true;
            }
            path.pop_back();
            return false;
        };
        findPath(findPath, 0);
            
        int m = path.size(); // {0, 1, 3}
        for (int i = 0; i < m/2; ++i)
            amount[path[m-i-1]] = 0;
        if (m & 1) // odd
            amount[path[m/2]] /= 2;
        
        // find the sum, when reach the leaf node
        int ans = INT_MIN;
        auto dfs = [&](auto &self, int u, int p=-1, int sum=0) -> void {
            sum += amount[u];
            if (u != 0 && tree[u].size() == 1) { // only has one parent and not root
                ans = max(ans, sum);
                return;
            }
            for (int v: tree[u]) if (v != p) {
                self(self, v, u, sum);
            }
        };
        dfs(dfs, 0);
        
        return ans;
    }
};
