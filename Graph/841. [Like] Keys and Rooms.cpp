// BFS. think it as graph.

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(q.size()){
            int u = q.front(); q.pop();
            for(int v: rooms[u]){
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        
        for(int i = 0; i < n; ++i) if(!vis[i]) return false;
        return true;
    }
};
