// DFS. O(2^N).
// Enum all case.

class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> res;
    void dfs(vector<int> &path, int u, int t){
        path.push_back(u);
        if(u == t){
            res.push_back(path);
            path.pop_back();
            return;
        }
        for(int v: g[u]){
            dfs(path, v, t);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        vector<int> path;
        dfs(path, 0, graph.size()-1);
        return res;
    }
};
