// !!! read the constraint. path is at most 10
// total 4^10
// T: O(10*4^10).

class Solution {
public:
    
    void dfs(int u, int curTime){
        if(u == 0){
            unordered_set<int> vis(path.begin(), path.end());
            int get = 0;
            for(int x: vis) get += values[x];
            ans = max(ans, get);
        }
        for(auto &[v, w]: graph[u]){
            if(curTime >= w){
                path.push_back(v);
                dfs(v, curTime-w);
                path.pop_back();
            }
        }
    }
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        // since path is at most 10
        // and each node edges is at most 4
        // totally possible will be 4^10
        
        graph.resize(values.size());
        this->values = values;
        
        // build graph
        for(auto &e: edges){
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        path.push_back(0);
        dfs(0, maxTime);
        return ans;
    }
    
private:
    vector<vector<pair<int, int>>> graph;
    vector<int> values, path;
    int ans=0;
};
