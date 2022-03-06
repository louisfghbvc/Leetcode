// each node, traverse the graph
// O(V(V+E)).

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // build the graph
        // for each node, try to traverse the graph, and push i to the node that is traverse
        
        vector<vector<int>> graph(n);
        for(auto &e: edges)
            graph[e[0]].push_back(e[1]);
        
        vector<vector<int>> res(n);
        for(int i = 0; i < n; ++i){
            vector<bool> vis(n);
            queue<int> q;
            q.push(i);
            while(q.size()){
                int u = q.front(); q.pop();
                for(int v: graph[u]){
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                        res[v].push_back(i);
                    }
                }
            }
        }
        
        return res;
    }
};
