//20ms 12.1MB O(N) the t maintain the level of tree, impressive, and pro hash all ans. 
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> g[n + 2];
        bool vis[n + 2] = {};
        double pro[n + 2] = {}; pro[1] = 1.0;
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(1);
        while(!q.empty() && t-- > 0){
            for(int size = q.size(); size > 0; -- size){
                int u = q.front(); q.pop();
                vis[u] = true;
                int nxt = 0;
                for(int &v : g[u]) if(!vis[v]) nxt++;
                for(int &v : g[u]){
                    if(vis[v]) continue;
                    pro[v] = pro[u] / (double)nxt;
                    q.push(v);
                }
                if(nxt) pro[u] = 0.0; //if have next, can not stay this node
            }
        }
        
        return pro[target];
    }
};
