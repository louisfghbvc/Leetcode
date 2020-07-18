// BFS O(V+E).

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses);
        vector<int> g[numCourses];
        for(auto &e: prerequisites){
            g[e[1]].push_back(e[0]);
            ind[e[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) if(!ind[i]){
            q.push(i);
        }
        
        vector<int> res;
        
        while(!q.empty()){
            for(int s = q.size()-1; s >= 0; --s){
                int u = q.front(); q.pop();
                res.push_back(u);
                for(auto &v: g[u]){
                    if(--ind[v] == 0)
                        q.push(v);
                }
            }
        }
        if(res.size() != numCourses) return {};
        return res;
    }
};

// also can use dfs.
