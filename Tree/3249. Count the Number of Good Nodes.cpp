class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        // goal: find out the number of good nodes that subtree has same size
        // idea:
        // post-order dfs, return tree size
        
        int n = edges.size()+1;
        vector<vector<int>> tree(n);
        
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
        int ans = 0;
        auto dfs = [&](auto &self, int u, int p=-1) -> int {
            
            vector<int> childs;
            
            int res = 1;
            for (int v: tree[u]) if (p != v) {
                int sz = self(self, v, u);
                childs.push_back(sz);
                res += sz;
            }
            
            if (childs.empty() || count(childs.begin(), childs.end(), childs[0]) == childs.size())
                ans++;
            
            return res;
        };
        
        dfs(dfs, 0);
        return ans;
    }
};
