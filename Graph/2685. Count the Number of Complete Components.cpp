class Solution {
public:
    
    vector<int> p;
    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }
    void uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // goal: count the complete components
        // idea: union find
        // first, record the graph 
        // second, merge the node
        // third, go through the node, check the parent, get the components -> check if existed all pairs
        
        vector vis(n, vector(n, false));
        p.assign(n, -1);
        
        for (auto &e: edges) {
            vis[e[0]][e[1]] = true;
            vis[e[1]][e[0]] = true;
            uni(e[0], e[1]);
        }
        
        unordered_map<int, vector<int>> graphs;
        for (int i = 0; i < n; ++i) {
            graphs[find(i)].push_back(i);
        }
        
        int ans = 0;
        for (auto &[a, v]: graphs) { 
            bool ok = true;
            for (int i = 0; i < v.size(); ++i) {
                for (int j = i+1; j < v.size(); ++j) {
                    if (!vis[v[i]][v[j]]) ok = false;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
