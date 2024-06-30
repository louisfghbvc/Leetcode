class Solution {
public:
    
    int treeCenter(vector<vector<int>>& edges) {
        // idea: use bfs, do indegree 0 first
        
        int n = edges.size()+1;
        if (n == 1) return 0;
        
        vector<vector<int>> tree(n);
        vector<int> ind(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
            ind[e[0]]++;
            ind[e[1]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 1) {
                q.push(i);
            }
        }
        
        int cnt = n;
        while (cnt > 2) {
            for (int i = q.size(); i > 0; --i) {
                int u = q.front(); q.pop();
                cnt--;
                for (int v: tree[u]) {
                    if (--ind[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }
        
        return q.front();
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        
        int n = edges.size()+1;
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
        int mxD = 0, mxNode = 0;
        auto dfs = [&](auto &self, int u, int dep=0, int p=-1) -> void {
            if (dep > mxD) {
                mxD = dep;
                mxNode = u;
            }
            for (int v: tree[u]) if (v != p) {
                self(self, v, dep+1, u);
            }
        };
        
        dfs(dfs, 0);
        
        mxD = 0;
        dfs(dfs, mxNode);
        return mxD;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // goal: find the minimum diameter after connect tree A and tree B
        // idea:
        // connect two tree center, after that we can compute the distance again
        
        
        int n = 1+edges1.size();
        int m = 1+edges2.size();
        
        int a = treeCenter(edges1), b = n + treeCenter(edges2);
        
        vector<vector<int>> edges3 = edges1;
        edges3.push_back({a, b});
        for (auto &e: edges2) {
            edges3.push_back({n+e[0], n+e[1]});
        }
        
        return treeDiameter(edges3);
    }
};
