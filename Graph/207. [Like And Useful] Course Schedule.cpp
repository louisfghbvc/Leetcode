// O(N+E), dfs. vis[u] = 1 is back edge, vis[u] = 2, cross edge.
// finding cycle. use topological sort.
class Solution {
public:
    bool cyc;
    void dfs(int u, vector<int> &vis, vector<vector<int>> &g){
        if(vis[u] == 1){
            cyc = 1; return;
        }
        if(vis[u] == 2) return; // cross
        vis[u] = 1;
        for(const auto&v: g[u])
            dfs(v, vis, g);
        vis[u] = 2; // end
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses+1);
        vector<vector<int>> g(numCourses+1, vector<int>());
        
        for(const auto & c: prerequisites){
            g[c[0]].push_back(c[1]);
        }
        
        cyc = 0;
        for(int i = 0; i < numCourses; ++i)
            if(!vis[i]) dfs(i, vis, g);
        
        return !cyc;
    }
};

// bfs. indegree 0 is first, and each node cnt. if cycle must cnt > N
// traversal each node make indegree-1.
// O(N+E), no recursive
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses+1);
        vector<vector<int>> g(numCourses+1, vector<int>());
        
        for(const auto & c: prerequisites){
            g[c[1]].push_back(c[0]);
            in[c[0]]++;
        }
        
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < numCourses; ++i)
            if(!in[i]) q.push(i);
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            cnt++;
            for(const auto &v: g[u]){
                if(--in[v] == 0) q.push(v);
            }
        }
        
        return cnt == numCourses;
    }
};

