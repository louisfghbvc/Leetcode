// scc, low[i]: in the same subtree under i, lowest reach time 
// dfs tree

class Solution {
public:
    
    void dfs(int u) {
        low[u] = dfn[u] = ++stamp;
        inst[u] = 1;
        st.push(u);
        
        for (int v: graph[u]) {
            if (!dfn[v]) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if (inst[v])
                low[u] = min(low[u], low[v]); // can use low, since is in same subtree
        }
        
        if (low[u] == dfn[u]) {
            int x;
            do {
                x = st.top(); st.pop();
                inst[x] = 0;
                group_sz[u]++;
            } while (x != u);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        // goal: find the cycle length
        // idea: tarjan algorithm, scc
        
        int n = edges.size();
        
        graph.resize(n);
        low.resize(n);
        dfn.resize(n);
        inst.resize(n);
        group_sz.resize(n);
        
        for (int i = 0; i < n; ++i)
            if (edges[i] != -1)
                graph[i].push_back(edges[i]);
        
        for (int i = 0; i < n; ++i) {
            if (!dfn[i])
                dfs(i);
        }
        
        int mx = 0;
        for (int i = 0; i < n; ++i) { 
            mx = max(mx, group_sz[i]);
        }
        
        if (mx >= 2) return mx;
        return -1; // no cycle
    }

private:
    vector<vector<int>> graph;
    vector<int> low, dfn, inst;
    stack<int> st;
    vector<int> group_sz;
    int stamp = 0;
};



// O(N), simple iterative, tricky, dfs tree

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        // goal: find the longest cycle length
        // idea: each node only have one outdegree
        // traverse the graph
        
        int n = edges.size();
        vector<int> dfn(n); // timestamp
        
        int res = -1;
        int time = 1;
        for (int i = 0; i < n; ++i) {
            int j = i, cur = time;
            while (j != -1 && !dfn[j]) {
                dfn[j] = time++;
                j = edges[j];
            }
            if (j != -1 && dfn[j] >= cur) // same root
                res = max(res, time - dfn[j]);
        }
        
        return res;
    }
};

