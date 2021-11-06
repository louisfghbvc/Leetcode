// Record edges. just look as graph.
// O(N). each points at most 2 candidates.
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> g;
        for(auto &e: adjacentPairs){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> res;
        for(auto &[k, v]: g){
            if(v.size() == 1){
                res.push_back(k);
                res.push_back(g[k][0]);
                break;
            }
        }
        while(res.size() < adjacentPairs.size()+1){
            int tail = res.back(), prev = res[res.size()-2];
            auto &can = g[tail];
            if(can[0] != prev) res.push_back(can[0]);
            else res.push_back(can[1]);
        }
        return res;
    }
};

// dfs, clean.
class Solution {
public:
    vector<int> res;
    set<int> vis; 
    unordered_map<int, vector<int>> g;
    void dfs(int u){
        for(int v: g[u]){
            if(!vis.count(v)){
                vis.insert(v);
                res.push_back(v);
                dfs(v);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adj) {
        
        for(auto &e: adj){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        int start = 0;
        for(auto &[k, v]: g){
            if(v.size() == 1){
                start = k; break;
            }
        }
        
        vis.insert(start);
        res.push_back(start);
        dfs(start);
        return res;
    }
};
