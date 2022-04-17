class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        // goal: find the length of 4 sequence, maximum the score
        // idea: each node just record largest 3, and enumerate the edge and update maximum
        
        int n = scores.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        for (int i = 0; i < n; ++i) {
            partial_sort(g[i].begin(), g[i].begin() + min<int>(3, g[i].size()), g[i].end(), [&](int x, int y) {
                return scores[x] > scores[y];    
            });
            if (g[i].size() > 3)
                g[i].resize(3);
        }
        
        // just enumerate the edge
        int ans = 0;
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            for (int nu: g[u]) {
                for (int nv: g[v]) {
                    if (nu != v && nv != u && nu != nv) {
                        ans = max(ans, scores[u] + scores[v] + scores[nu] + scores[nv]);
                    }
                }
            }
        }
        
        return ans == 0 ? -1 : ans;
    }
};
